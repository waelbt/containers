/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 05:19:27 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/14 07:03:36 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_ITERATOR
# define TREE_ITERATOR

namespace ft
{
	template<class T, class Node>
	class tree_iterator
	{
		public:
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef T								value_type;
			typedef ptrdiff_t						difference_type;
			typedef value_type&                     reference;
			typedef Node* 							pointer;
		private:
			pointer _ptr;
		public:
			tree_iterator() : _ptr(NULL) {}
			tree_iterator(pointer ptr) : _ptr(ptr) {}
			tree_iterator(const tree_iterator& obj) : _ptr(obj._ptr){}
			tree_iterator& operator=(const tree_iterator& obj){
				_ptr = obj._ptr;
				return *this;}
			pointer operator->()  { return _ptr; }
			reference operator*(){
				return _ptr->_value;}
			bool operator== (const tree_iterator& rhs) const
			{return (_ptr == rhs._ptr);}
    		bool operator!= (const tree_iterator& rhs) const
			{return (_ptr != rhs._ptr);}
			tree_iterator operator++() 
			{
				pointer tmp;

    			if (_ptr->_right != NULL)
      			{
        			_ptr = _ptr->_right;
        			while (_ptr->_left != NULL) {
          				_ptr = _ptr->_left;
        			}
      			}
    			else
      			{
        			tmp = _ptr->parent;
        			while (tmp != NULL && _ptr == tmp->_right)
          			{
            			_ptr = tmp;
            			tmp = tmp->parent;
          			}
        			_ptr = tmp;
      			}
				return *this;
			}
			// tree_iterator operator++(int) {}
			// tree_iterator operator--() {}
			// tree_iterator operator--(int) {}
	};
}

# endif