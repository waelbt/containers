/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:26:50 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/14 03:39:36 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

# define _RIGHT 0
# define _LEFT  1

# include "../utility/less.hpp"
# include "tree_iterator.hpp"
# include "../utility/pair.hpp"
# include "../utility/reverse_iterator.hpp"
# include "../utility/iterator_traits.hpp"

//select pair
//select key 

// namespace ft
// {
	template <typename T>
	class Node 
	{
		public :
			typedef T					value_type;
			typedef	Node<T>*			pointer;
			typedef	Node<T>&			reference;
			typedef	const Node<T>&		const_reference;

			value_type	_value;
			bool		_black;
			pointer		_parent;
			pointer		_left;
			pointer		_right;

		Node(value_type val) : _value(val), _black(false), _parent(), _left(), _right() {}
		Node(const_reference obj) : _value(obj._value), _black(obj._black), _parent(obj._parent),_left(obj._left), _right(obj._right) {}
		const_reference operator=(const_reference obj){
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
		~Node(){}
	};

	template <typename T, class Compare, class Alloc = std::allocator<T> >
	class TREE
	{
		public:

			typedef		T															value_type;
			typedef 	Alloc               										allocator_type;
			typedef 	typename allocator_type::template rebind<Node<T> >::other	node_allocater;
			typedef		Compare                                  					value_compare;
			typedef		typename node_allocater::value_type							node_type;
			typedef		typename node_allocater::pointer 							pointer;
			typedef		typename node_allocater::const_pointer 						const_pointer;
			typedef		typename node_allocater::difference_type					difference_type;
			typedef 	typename node_allocater::size_type 							size_type;
			typedef 	ft::tree_iterator<value_type, node_type> 					iterator;
			typedef 	ft::tree_iterator<const value_type, node_type> 				const_iterator;
			typedef 	typename ft::reverse_iterator<iterator>						reverse_iterator;
			typedef 	typename ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			struct		delete_tag {};
			struct		insert_tag {};
			struct		min_tag {static const bool value = true;};
			struct		max_tag {static const bool value = false;};

		private:
			pointer 		_root;
			pointer			_nill;
			node_allocater 	_alloc;
			value_compare	 _comp;
			size_type		_size;
		public:
			TREE(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0){
				_nill = construct_nill();
				_root = _nill;
			}

			TREE(const TREE& x)
			{
				_alloc = x._alloc;
				_nill = construct_nill();
				_root = copy(x._root, x._nill, _nill);
				_comp = x._comp;
				_size = x._size;
			}

			void swap (TREE& x)
			{
				ft::swap(_root, x._root);
				ft::swap(_nill, x._nill);
				ft::swap(_alloc, x._alloc);
				ft::swap(_comp, x._comp);
				ft::swap(_size, x._size);
			}

			TREE& operator=(const TREE& x)
			{
				if (_root != _nill)
					this->clear();
				_root = copy(x._root, x._nill, _nill);
				_comp = x._comp;
				_size = x._size;
				return *this;
			}
			pointer copy(pointer node, pointer obj_Nill, pointer& _nill)
			{
				pointer new_node;

				if (node == obj_Nill)
					return _nill;
				new_node = construct_node(node->_value);
				new_node->_left = copy(node->_left, obj_Nill, _nill);
				new_node->_left->_parent = new_node;
				new_node->_right = copy(node->_right, obj_Nill, _nill);
				new_node->_right->_parent = new_node;
				return new_node;
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _alloc. max_size();
			}

			iterator insert(const value_type& key)
			{
				pointer new_node;
				pointer tmp;
				new_node = construct_node(key);
				bst_insertion(_root, new_node);
				tmp = new_node;
				while (!new_node->_parent->_black)
				{
 					if (new_node->_parent == new_node->_parent->_parent->_right)
						FixUp(new_node, _RIGHT);
					else
						FixUp(new_node, _LEFT);
				}
				_root->_black = true;
				return iterator(tmp, _root ,_nill);
			}

			void deletion (value_type key)
			{
				pointer	node;
				pointer x;
				bool	black;

				node = search(_root, key);
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

			iterator begin()
			{
				return iterator(getter(_root, min_tag()), _root, _nill);
			}

			iterator end()
			{
				return iterator(_nill, _root, _nill);
			}

			const_iterator begin() const
			{
				return  const_iterator(getter(_root, min_tag()), _root, _nill);
			}

			const_iterator end() const
			{
				return const_iterator(_nill, _root, _nill);
			}

			reverse_iterator rbegin()
			{
				return reverse_iterator(end());
			}

			reverse_iterator rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			iterator search(const value_type& key)
			{
				return iterator(search(_root, key), _root, _nill);
			}

			const_iterator search(const value_type& key) const
			{
				return const_iterator(search(_root, key), _root, _nill);
			}


			~TREE()
			{
				if(_root != _nill)
					clear();
				destroy_node(_nill);
			}

			void clear()
			{
				clear(_root);
				_root = _nill;
			}

			bool empty() const
			{
				return (_(_root));
			}

			iterator lower_bound (const value_type& k) const
			{
				pointer node = _root;
				pointer resultat = _nill;
				while (node != _nill)
				{
					if(!_comp(node->_value, k))
					{
						resultat = node;
						node = node->_left;
					}
					else
						node = node->_right;
				}
				return iterator(resultat, _root, _nill);
			}

			iterator upper_bound (const value_type& k) const
			{
				pointer node = _root;
				pointer resultat = _nill;

				while (node != _nill)
				{
					if(_comp(k, node->_value))
					{
						resultat = node;
						node = node->_left;
					}
					else
						node = node->_right;
				}
				return iterator(resultat, _root, _nill);
			}

			
			// const_iterator lower_bound (const value_type& k) const
			// {
			// 	pointer node = _root;
			// 	pointer resultat = _nill;
			// 	while (node != _nill)
			// 	{
			// 		if(!_comp(node->_value, k))
			// 		{
			// 			resultat = node;
			// 			node = node->_left;
			// 		}
			// 		else
			// 			node = node->_right;
			// 	}
			// 	return const_iterator(resultat, _root, _nill);
			// }

			// const_iterator upper_bound (const value_type& k) const 
			// {
			// 	pointer node = _root;
			// 	pointer resultat = _nill;

			// 	while (node != _nill)
			// 	{
			// 		if(_comp(k, node->_value))
			// 		{
			// 			resultat = node;
			// 			node = node->_left;
			// 		}
			// 		else
			// 			node = node->_right;
			// 	}
			// 	return const_iterator(resultat, _root, _nill);
			// }

		private:

			pointer construct_nill()
			{
				pointer node;

				node = _alloc.allocate(1);
				_alloc.construct(node, value_type());
				node->_black = true;
				return node;
			}

			pointer construct_node(const value_type& key)
			{
				pointer node;

				node = _alloc.allocate(1);
				_alloc.construct(node, key);
				node->_left = _nill;
				node->_right = _nill;
				node->_parent = _nill;
				_size++;
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

			bool _(const pointer& x) const
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
				if (_(node->_right) || _(node->_left))
				{
					x = getchild(node, _(node->_right));
					transplant(node, getchild(node, _(node->_right)));
				}
				if (!_(node->_right) && !_(node->_left))
				{
					tmp = getter(node->_right, min_tag());
					black = tmp->_black;
					x = tmp->_right;
					if (tmp != node->_right)
					{
						transplant(tmp, tmp->_right);
						connect(tmp, node, _RIGHT);
					}
					else
						x->_parent = tmp;
					transplant(node, tmp);
					connect(tmp, node, _LEFT);
					tmp->_black = node->_black;
				}
			}

			void color_flipping(pointer& node, pointer& uncle)
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
				if (_comp(new_node->_value, node->_value))
					bst_insertion(node->_left, new_node);
				else if (_comp(node->_value, new_node->_value))
					bst_insertion(node->_right, new_node);
			}

			template <typename tag>
			pointer getter(pointer node, tag) const
			{
				if (node != _nill)
				{
					while (!_(getchild(node, tag::value))){
						node = getchild(node, tag::value);}
				}
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
				if (uncle && !uncle->_black)
					color_flipping(node, uncle);
				else
				{
					if (node == getchild(node->_parent, !isLeft))
					{
						node = node->_parent;
						rotate(node, isLeft);
					}
					if (node->_parent)
						node->_parent->_black = true;
					if (node->_parent->_parent && node->_parent->_parent != _nill)
					{
						node->_parent->_parent->_black = false;
						rotate(node->_parent->_parent, !isLeft);
					}
				}
			}

			void FixUp(pointer& node, bool isRight, delete_tag)
			{
				pointer tmp;

				tmp = getchild(node->_parent, isRight);
				if (tmp) {
					node = _root; return ;}
				if (!tmp->_black)
				{
					tmp->_black = true;
					node->_parent->_black = false;
					rotate(node->_parent, !isRight);
					tmp = getchild(node->_parent, isRight);
				}
				if (tmp != _nill && tmp->_right->_black && tmp->_left->_black)
				{
					tmp->_black = false;
					node = node->_parent;
				}
				else
				{
					if ((getchild(tmp, isRight)!= _nill) && getchild(tmp, isRight)->_black)
					{
						getchild(tmp, !isRight)->_black = true;
						tmp->_black = false;
						rotate(tmp, isRight);
						tmp = getchild(node->_parent, isRight);
					}
					tmp->_black = node->_parent->_black;
					node->_parent->_black = true;
					getchild(tmp, isRight)->_black = true;
					rotate(node->_parent, !isRight);
					node = _root;
				}
			}
			
			pointer& search(pointer& node, const value_type& key)
			{
				if (node != _nill)
				{
    				if (_comp(key, node->_value))
       					return search(node->_left, key);
					else if (_comp(node->_value, key))
						return search(node->_right, key);
				}
       			return node;
			}

			const pointer& search(const pointer& node, const value_type& key) const
			{
				if (node != _nill)
				{
    				if (_comp(key, node->_value))
       					return search(node->_left, key);
					else if (_comp(node->_value, key))
						return search(node->_right, key);
				}
       			return node;
			}
			
			void destroy_node(pointer& node)
			{
				if (node)
				{
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					_size--;
				}
				node = NULL;
			}

			void clear(pointer& node)
			{
				if (node != _nill)
				{
					if (node->_left != _nill)
						clear(node->_left);
					if (node->_right != _nill)
						clear(node->_right);
					destroy_node(node);
				}
			}
			// void print(pointer node, const pointer& nill)
			// {
			// 	if (node == nill)
			// 	{
			// 		return ;
			// 	}
			// 	print(node->_left, nill);
			// 	print(node->_right, nill);
			// }

		};
// } // namespace ft	

#endif
