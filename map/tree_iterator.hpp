/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:19:27 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/18 04:56:19 by waboutzo         ###   ########.fr       */
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
			typedef typename ft::remove_cv<T>::type	value_type;
			typedef ptrdiff_t						difference_type;
			typedef T&                     			reference;
			typedef typename Node::pointer 			iter_pointer;
			typedef T* 								pointer;
		private:
			iter_pointer _ptr;
			iter_pointer _root;
			iter_pointer _nill;
		public:
			tree_iterator() : _ptr(NULL), _root(NULL), _nill(NULL) {}
			tree_iterator(iter_pointer ptr, iter_pointer root, iter_pointer nill) : _ptr(ptr) ,_root(root), _nill(nill){}
			iter_pointer& base() const {return _ptr;}
			tree_iterator(const tree_iterator& obj) : _ptr(obj._ptr), _root(obj._root),_nill(obj._nill){}
			operator tree_iterator<const value_type, Node>(){
        		return tree_iterator<const value_type, Node>(_ptr, _root ,_nill);}
			tree_iterator& operator=(const tree_iterator& obj){
				_ptr = obj._ptr;
				_root = obj._root;
				_nill = obj._nill;
				return *this;}
			pointer operator->() const{ return &_ptr->_value; }
			reference operator*() const{
				return  _ptr->_value;}
			template<class U, class S>
			friend bool operator== (const tree_iterator<U, Node>& rhs, const tree_iterator<S, Node>& ths)
			{return (rhs._ptr == ths._ptr);}
	
			template<class U, class S>
			friend bool operator!= (const tree_iterator<U, Node>& rhs, const tree_iterator<S, Node>& ths)
			{return (!(rhs == ths));}

			tree_iterator& operator++() 
			{
				iter_pointer tmp;

    			if (_ptr->_right != _nill)
      			{
					//getter function
        			_ptr = _ptr->_right;
        			while (_ptr->_left !=  _nill) {
          				_ptr = _ptr->_left;
        			}
      			}
    			else
      			{
        			tmp = _ptr->_parent;
        			while (tmp != _nill && _ptr == tmp->_right)
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
				if (_ptr == _nill)
    			{
    				_ptr = _root;
    				while (_ptr->_right != _nill) {
    				  _ptr = _ptr->_right;
    				}
    			}
				else
				{
					//getter function
    				if (_ptr->_left != _nill)
      				{
        				_ptr = _ptr->_left;
        				while (_ptr->_right !=  _nill) {
          					_ptr = _ptr->_right;
        				}
      				}
    				else
      				{
        				tmp = _ptr->_parent;
        				while (tmp != _nill && _ptr == tmp->_left)
          				{
            				_ptr = tmp;
            				tmp = tmp->_parent;
          				}
        				_ptr = tmp;
      				}
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