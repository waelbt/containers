/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:26:50 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/10 22:14:03 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP


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
						fixe_tree(new_node, false);
					else
						fixe_tree(new_node, true);
				}
				_root->_black = true;
			}
			
			void deletion (value_type key)
			{
				pointer	node;
				pointer x;
				bool	color;

				node = search(key);
				if (node != _nill)
				{ 
					x = delete_node(node, color);
				}
			}

			pointer search(value_type key)
			{
				return search(_root, key);
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

			bool _(pointer& x)
			{
				return (x == _nill);
			}

			void connect(pointer& node1, pointer& node2, bool side)
			{
				pointer& child = getchild(node1, side);
				child = getchild(node2, side);
				child->_parent = node1;
			}

			pointer delete_node(pointer& node, bool& color)
			{
				pointer tmp = node;
				pointer x;

				color = tmp->_black;
				if (!_(node->_right) && !_(node->_left))
				{
					tmp = tree_minimum(node->_right);
					color = node->_black;
					x = tmp->_right;
					if (tmp != node->_right)
					{
						transplant(tmp, tmp->_right);
						connect(tmp, node, false);
					}
					else
						x->_parent = tmp;
					transplant(node, tmp);
					connect(tmp, node, true);
					tmp->_black = color;
				}
				else
				{
					x = getchild(node, _(node->_right));
					transplant(node, getchild(node, _(node->_right)));
				}
				return x;
			}

			void recoloring(pointer& node, pointer& uncle)
			{
				uncle->_black = true;
				node->_parent->_black = true;
				node->_parent->_parent->_black = false;
				node = node->_parent->_parent;
			}

			void rotate(pointer node, bool side){
				pointer tmp;
	
				tmp = getchild(node, !side);
				getchild(node, !side) = getchild(tmp, side);
				if(getchild(tmp, side))
					getchild(tmp, side)->_parent = node;
				tmp->_parent = node->_parent;
				if (_(node->_parent))
					_root = tmp;
				else if (node == node->_parent->_left)
					node->_parent->_left = tmp;
				else 
					node->_parent->_right = tmp;
				getchild(tmp, side) = node;
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

			pointer tree_minimum(pointer node)
			{
				while (node->_left != _nill)
					node = node->_left;
				return node;
			}

			pointer tree_maxmum(pointer node)
			{
				while (node->_right != _nill)
					node = node->_right;
				return node;
			}

			// void bst_deletion(pointer& node, value_type value)
			// {
			// 	pointer tmp;

			// 	if (node != _nill)
			// 	{
			// 		if (value == node->_value)
			// 		{
			// 			if (_(node->_left) && _(node->_right))
			// 				delete_node(node);
			// 			else if (_(node->_left) || _(node->_right))
			// 			{ 
			// 				tmp = node;
			// 				node = (_(node->_left)) ? node->_right : node->_left;
			// 				delete_node(tmp);
			// 			}
			// 			else 
			// 			{
			// 				tmp = tree_minimum(node->_right);
			// 				node->_value = tmp->_value;
			// 				bst_deletion(node->_right, tmp->_value);
			// 			}
			// 		}
			// 		else if (value < node->_value)
			// 			bst_deletion(node->_left, value);
			// 		else if (value > node->_value)
			// 			bst_deletion(node->_right, value);
			// 	}
			// }

			pointer& getchild(pointer& node, bool side) {
				if (side)
					return node->_left;
				return node->_right;
			}

			void fixe_tree(pointer& new_node, bool side)
			{
				pointer uncle;

				uncle = getchild(new_node->_parent->_parent, !side);
				if (!uncle->_black)
					recoloring(new_node, uncle);
				else
				{
					if (new_node == getchild(new_node->_parent, !side))
					{
						new_node = new_node->_parent;
						rotate(new_node, side);
					}
					new_node->_parent->_black = true;
					new_node->_parent->_parent->_black = false;
					rotate(new_node->_parent->_parent, !side);
				}
			}

			pointer search(pointer node, value_type key)
			{
				if (node == _nill || node->_value == key)
       				return node;
    			if (node->_value < key)
       				return search(node->_right, key);
				return search(node->_left, key);
			}

		};
// } // namespace ft	



#endif

