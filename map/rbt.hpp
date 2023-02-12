/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:26:50 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/12 22:40:48 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# define _RIGHT 0
# define _LEFT  1

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
			struct		delete_tag {};
			struct		insert_tag {};
			struct		min_tag {static const bool value = true;};
			struct		max_tag {static const bool value = false;};

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

			pointer getROOT() const
			{
				return _root;
			}

			void insert(value_type key)
			{
				pointer new_node;

				new_node = construct_node(key);
				bst_insertion(_root, new_node);
				while (!new_node->_parent->_black)
				{
 					if (new_node->_parent == new_node->_parent->_parent->_right)
						FixUp(new_node, _RIGHT);
					else
						FixUp(new_node, _LEFT);
				}
				_root->_black = true;
			}

			void deletion (value_type key)
			{
				pointer	node;
				pointer x;
				bool	black;

				node = search(key);
				if (node != _nill)
				{ 
					delete_node(node ,x , black);
					if (black)
					{
						while (x != _root && x->_black)
						{
							if (x == x->_parent->_left)
								FixUp(x, _RIGHT, delete_tag());
							else
								FixUp(x, _LEFT, delete_tag());
						}
						x->_black = true;
					}
					destroy_node(node);
				}
			}

			pointer search(value_type key) const
			{
				return search(_root, key);
			}

			~RBT()
			{
				if(_root != _nill)
					delete_tree(_root);
				destroy_node(_nill);
			}

		private:

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
			
			void transplant(pointer u, pointer v)
			{
				if (_(u->_parent))
					_root = v;
				else if (u == u->_parent->_left)
					u->_parent->_left = v;
				else
					u->_parent->_right = v;
				v->_parent = u->_parent;
			}

			bool _(pointer& x) const
			{
				return (x == _nill);
			}

			void connect(pointer& node1, pointer& node2, bool isLeft)
			{
				pointer& child = getchild(node1, isLeft);

				child = getchild(node2, isLeft);
				child->_parent = node1;
			}

			void delete_node(pointer& node, pointer& x, bool& black)
			{
				pointer tmp = node;

				black = tmp->_black;
				if (!_(node->_right) && !_(node->_left))
				{
					tmp = getter(node->_left, max_tag());
					black = tmp->_black;
					x = tmp->_left;
					if (tmp != node->_left)
					{
						transplant(tmp, tmp->_left);
						connect(tmp, node, _LEFT);
					}
					else
						x->_parent = tmp;
					transplant(node, tmp);
					connect(tmp, node, _RIGHT);
					tmp->_black = node->_black;
				}
				else
				{
					x = getchild(node, _(node->_right));
					transplant(node, getchild(node, _(node->_right)));
				}
			}

			void recoloring(pointer& node, pointer& uncle)
			{
				uncle->_black = true;
				node->_parent->_black = true;
				node->_parent->_parent->_black = false;
				node = node->_parent->_parent;
			}

			void rotate(pointer node, bool isLeft){
				pointer tmp;

				tmp = getchild(node, !isLeft);
				getchild(node, !isLeft) = getchild(tmp, isLeft);
				if(getchild(tmp, isLeft))
					getchild(tmp, isLeft)->_parent = node;
				tmp->_parent = node->_parent;
				if (_(node->_parent))
					_root = tmp;
				else if (node == node->_parent->_left)
					node->_parent->_left = tmp;
				else 
					node->_parent->_right = tmp;
				getchild(tmp, isLeft) = node;
				node->_parent = tmp;
			}

			void	bst_insertion(pointer& node, pointer& new_node)
			{
				if (_(node)){
					node = new_node; return ;}
				new_node->_parent = node;
				if (new_node->_value <= node->_value)
					bst_insertion(node->_left, new_node);
				else if (new_node->_value > node->_value)
					bst_insertion(node->_right, new_node);
			}

			template <typename tag>
			pointer getter(pointer node, tag) const
			{
				while (!_(getchild(node, tag::value)))
					node = getchild(node, tag::value);
				return node;
			}

			pointer& getchild(pointer& node, bool isLeft) const
			{
				return (((isLeft)) ? (node->_left) : (node->_right));
			}

			void FixUp(pointer& node, bool isLeft, insert_tag = insert_tag())
			{
				pointer uncle;

				uncle = getchild(node->_parent->_parent, !isLeft);
				if (!uncle->_black)
					recoloring(node, uncle);
				else
				{
					if (node == getchild(node->_parent, !isLeft))
					{
						node = node->_parent;
						rotate(node, isLeft);
					}
					node->_parent->_black = true;
					node->_parent->_parent->_black = false;
					rotate(node->_parent->_parent, !isLeft);
				}
			}

			void FixUp(pointer& node, bool isRight, delete_tag)
			{
				pointer tmp;

				tmp = getchild(node->_parent, isRight);
				if (!tmp->_black)
				{
					tmp->_black = true;
					node->_parent->_black = false;
					rotate(node->_parent, !isRight);
					tmp = getchild(node->_parent, isRight);
				}
				if (tmp->_right->_black && tmp->_left->_black)
				{
					tmp->_black = false;
					node = node->_parent;
				}
				else
				{
					if (getchild(tmp, isRight)->_black)
					{
						getchild(tmp, !isRight)->_black = true;
						tmp->_black = false;
						rotate(tmp, isRight);
						tmp = getchild(tmp, isRight);
					}
					tmp->_black = node->_parent->_black;
					node->_parent->_black = true;
					getchild(tmp, isRight)->_black = true;
					rotate(node->_parent, !isRight);
					node = _root;
				}
			}
			
			pointer search(pointer node, value_type key) const
			{
				if (node == _nill || node->_value == key)
       				return node;
    			if (node->_value < key)
       				return search(node->_right, key);
				return search(node->_left, key);
			}

			void destroy_node(pointer& node)
			{
				if (node)
				{
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
				}
				node = NULL;
			}

			void delete_tree(pointer& node)
			{
				if (node->_left != _nill)
					delete_tree(node->_left);
				if (node->_right != _nill)
					delete_tree(node->_right);
				destroy_node(node);
			}

		};
// } // namespace ft	



#endif
