/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:26:50 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/08 09:07:30 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#define BLACK   "\033[m"      /* Black */
#define RED     "\033[31m"      /* Red */

// namespace ft
// {
	template <typename T>
	class Node 
	{
		public :
			typedef T					value_type;
			typedef	Node<T>*			pointer;
			typedef	Node<T>&			reffrence;
			typedef	const Node<T>&		const_reffrence;

			value_type	_value;
			bool		_black;
			pointer		_parent;
			pointer		_left;
			pointer		_right;

		Node(value_type val) : _value(val), _black(false), _parent(), _left(), _right() {}
		Node(const_reffrence obj) {*this = obj;}
		const_reffrence operator=(const_reffrence obj){
			if (this != &obj)
			{
				_value = obj._value;
				_black = obj._black;
				_left = obj._left;
				_right = obj._right;
				_parent = obj._parent;
			}
			return *this;
		}
		~Node(){/*i will implement it later*/}	
	};
	template <typename T, class Alloc = std::allocator<T> >
	class RBT
	{
		public:
			typedef		T 															value_type;
			typedef 	Alloc               										allocator_type;
			typedef 	typename allocator_type::template rebind<Node<T> >::other	node_allocater;
			typedef		typename node_allocater::value_type							node_type;
			typedef		typename node_allocater::pointer 							pointer;
			typedef		typename node_allocater::const_pointer 						const_pointer;
			typedef		typename node_allocater::difference_type					difference_type;
			typedef 	typename node_allocater::size_type 							size_type;
			//iterator
			//const_iterator
			//reverse_iteator
			//const_reverse_iteator
			// typedef		typename node_allocater::reffrence							reffrence;
			// typedef		typename node_allocater::const_reffrence					const_reffrence;
		private:
			pointer 		_root;
			pointer			_nill;
			node_allocater _alloc;
		public:
			RBT(const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
				_nill = _alloc.allocate(1);
				_alloc.construct(_nill, value_type());
				_nill->_black = true;
				_root = _nill;
			}
			pointer getROOT() const{return _root;}
			void insert(T key)
			{
				pointer new_node;

				new_node = construct_node(key);
				bst_insertion(_root, new_node);
				insert_fixedup(new_node);
				_root->_black = true;
			}
			pointer search(value_type key){
				return search(_root, key);
			}
			void skip_to_next_level(std::pair<pointer, int> current)
			{
				static int last_level = -1;
				if (last_level == current.second)
					std::cout << " ";
				if ((last_level != current.second) && current.first->_parent)
					std::cout << std::endl;
				last_level = current.second;
			}
			void breadthFirstTraversal(){
				std::deque<std::pair<pointer, int> > queue;
				queue.push_back(std::make_pair(_root, 0));
				while (!queue.empty())
				{
					std::pair<pointer, int> current = queue.front();
					queue.pop_front();
					skip_to_next_level(current);
					std::cout << ((current.first->_black) ? BLACK : RED) << current.first->_value;
					if (current.first->_parent)
						std::cout << '(' << current.first->_parent->_value << ')' << " ";
					if (current.first->_left)
						queue.push_back(std::make_pair(current.first->_left, (current.second + 1)));
					if (current.first->_right)
						queue.push_back(std::make_pair(current.first->_right, (current.second + 1)));
				}
			}
		public:
			pointer construct_node(value_type key)
			{
				pointer node;

				node = _alloc.allocate(1);
				_alloc.construct(node, key);
				node->_left = _nill;
				node->_right = _nill;
				node->_parent = _nill;
				return node;
			}
			void left_rotate(pointer node){
				pointer tmp;

				tmp = node->_right;
				node->_right = tmp->_left;
				if(tmp->_left)
					tmp->_left->_parent = node;
				tmp->_parent = node->_parent;
				if (node->_parent == _nill)
					_root = tmp;
				else if (node == node->_parent->_left)
					node->_parent->_left = tmp;
				else 
					node->_parent->_right = tmp;
				tmp->_left = node;
				node->_parent = tmp;
			}
			void right_rotate(pointer node)
			{
				pointer tmp;

				tmp = node->_left;
				node->_left = tmp->_right;
				if(tmp->_right)
					tmp->_right->_parent = node;
				tmp->_parent = node->_parent;
				if (node->_parent == _nill)
					_root = tmp;
				else if (node == node->_parent->_right)
					node->_parent->_right = tmp;
				else 
					node->_parent->_left = tmp;
				tmp->_right = node;
				node->_parent = tmp;
			}
			void	bst_insertion(pointer& node, pointer& new_node)
			{
				if (node == _nill)
					node = new_node;
				else if (new_node->_value <= node->_value)
				{
					new_node->_parent = node;
					bst_insertion(node->_left, new_node);
				}
				else if (new_node->_value > node->_value)
				{
					new_node->_parent = node;
					bst_insertion(node->_right, new_node);
				}
			}
			void	insert_fixedup(pointer& new_node)
			{
				pointer uncle;

				while (!new_node->_parent->_black)
				{
 					if (new_node->_parent == new_node->_parent->_parent->_right)
					{
						uncle = new_node->_parent->_parent->_left;
						if (!uncle->_black)
						{
							uncle->_black = true;
							new_node->_parent->_black = true;
							new_node->_parent->_parent->_black = false;
							new_node = new_node->_parent->_parent;
						}
						else
						{
							if (new_node == new_node->_parent->_left)
							{
								new_node = new_node->_parent;
								right_rotate(new_node);
							}
							new_node->_parent->_black = true;
							new_node->_parent->_parent->_black = false;
							left_rotate(new_node->_parent->_parent);
						}
					}
					else if (new_node->_parent == new_node->_parent->_parent->_left)
					{
						uncle = new_node->_parent->_parent->_right;
						if (!uncle->_black)
						{
							uncle->_black = true;
							new_node->_parent->_black = true;
							new_node->_parent->_parent->_black = false;
							new_node = new_node->_parent->_parent;
						}
						else
						{
							if (new_node == new_node->_parent->_right)
							{
								new_node = new_node->_parent;
								left_rotate(new_node);
							}
							new_node->_parent->_black = true;
							new_node->_parent->_parent->_black = false;
							right_rotate(new_node->_parent->_parent);
						}
					}
				}
			}
			pointer search(pointer node, value_type key)
			{
				if (node == NULL || node->_value == key)
       				return node;
    			if (node->_value < key)
       				return search(node->_right, key);
				return search(node->_left, key);
			}
		};
// } // namespace ft	



#endif
