/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:19:27 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/15 05:27:15 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR
# define TREE_ITERATOR

# include <iostream>
# include "../vector/type_traits.hpp"
namespace ft
{
	template<class T, class Node>
	class tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef ft::remove_cv<T>				value_type;
			typedef ptrdiff_t						difference_type;
			typedef T&                     			reference;
			typedef typename Node::pointer 			iter_pointer;
			typedef T* 								pointer;
		private:
			iter_pointer _ptr;
		public:
			tree_iterator() : _ptr(NULL) {}
			tree_iterator(iter_pointer ptr) : _ptr(ptr) {}
			tree_iterator(const tree_iterator& obj) : _ptr(obj._ptr){}
			operator tree_iterator<const value_type, Node>(){
        		return tree_iterator<const value_type, Node>(_ptr);}
			tree_iterator& operator=(const tree_iterator& obj){
				_ptr = obj._ptr;
				return *this;}
			pointer operator->() const{ return &(_ptr->_value); }
			reference operator*() const{
				return _ptr->_value;}
			bool operator== (const tree_iterator& rhs) const
			{return (_ptr == rhs._ptr);}
    		bool operator!= (const tree_iterator& rhs) const
			{return (_ptr != rhs._ptr);}
			tree_iterator& operator++() 
			{
				iter_pointer tmp;

    			if (_ptr->_right != _ptr->_nill)
      			{
        			_ptr = _ptr->_right;
        			while (_ptr->_right !=  _ptr->_nill) {
          				_ptr = _ptr->_left;
        			}
      			}
    			else
      			{
        			tmp = _ptr->_parent;
        			while (tmp != _ptr->_nill && _ptr == tmp->_right)
          			{
            			_ptr = tmp;
            			tmp = tmp->_parent;
          			}
        			_ptr = tmp;
      			}
				return *this;
			}
			tree_iterator operator++(int) {
				tree_iterator tmp(*this);

				++(*this);
				return tmp;
			}
			
			tree_iterator& operator--() 
			{
				iter_pointer tmp;

    			if (_ptr->_left != _ptr->_nill)
      			{
        			_ptr = _ptr->_left;
        			while (_ptr->_right !=  _ptr->_nill) {
          				_ptr = _ptr->_right;
        			}
      			}
    			else
      			{
        			tmp = _ptr->_parent;
        			while (tmp != _ptr->_nill && _ptr == tmp->_left)
          			{
            			_ptr = tmp;
            			tmp = tmp->_parent;
          			}
        			_ptr = tmp;
      			}
				return *this;
			}
			tree_iterator operator--(int) {
				tree_iterator tmp(*this);

				--(*this);
				return tmp;
			}
			// tree_iterator operator--() {}
			// tree_iterator operator--(int) {}
	};
}

# endif