/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:26:50 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/28 18:51:14 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

namespace ft
{
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

		Node(value_type val) : _value(val), _black(0), _parent(), _left(), _right() {}
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
			node_allocater _alloc;
		public:
			RBT(const allocator_type& alloc = allocator_type()) : _root(), _alloc(alloc) {}
			
	};
} // namespace ft	



#endif
