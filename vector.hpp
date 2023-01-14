/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:56 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/13 10:19:25 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_HPP
# define	VECTOR_HPP

# include <iostream>
# include "tools.hpp"
# include <vector>
# include <type_traits>
# include "iterator.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T 															value_type;
			typedef Alloc														allocator_type;
			typedef	value_type&													reference;
			typedef	const value_type&											const_reference;
			typedef	typename allocator_type::pointer							pointer;
			typedef	typename allocator_type::const_pointer						const_pointer;
			typedef	typename ft::iterator<T>									iterator; // the vector itertor is just temporary i will remove it 
			typedef	typename ft::iterator<const T>								const_iterator; // the vector itertor is just temporary i will remove it 
			typedef typename ft::reverse_iterator<iterator>						reverse_iterator; //tmp
			typedef typename ft::reverse_iterator<const_iterator>				const_reverse_iterator; //tmp
			typedef ptrdiff_t													difference_type;
			typedef typename allocator_type::size_type 							size_type;

		private:
			pointer			_begin;
			pointer			_end;
			pointer			_end_cap;
			allocator_type	_alloc;

		public:
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc){
				difference_type size;
				
				size = last - first;
				_begin = _alloc.allocate(size);
				_end = _begin + size;
				_end_cap = _end;
				for(pointer i = _begin; i < _end; i++)
					_alloc.construct(i, *(first++));
			}
			vector (const vector& x);
			
			vector& operator= (const vector& x);

			~vector();

			/******* Iterators ************/
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;

			reverse_iterator rbegin(){
				return reverse_iterator(end());}
		
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(end());}
			
			reverse_iterator rend(){
				return reverse_iterator(begin());}
		
			const_reverse_iterator rend() const{
				return const_reverse_iterator(begin());}
			/******* Iterators ************/
			size_type size() const;
			size_type max_size() const;
			size_type capacity() const;
			bool empty() const;
			void resize (size_type n, value_type val = value_type());
			void reserve (size_type n);

			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last){
				this->clear();
				for (InputIterator it = first; it != last; it++)
					push_back(*it);
			}
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last){
				vector<T, Alloc> tmp;
				ft::vector<T, Alloc>::iterator it;
		
				for (it = begin(); it != position; it++)
					tmp.push_back(*it);
				for (InputIterator it = first; it != last; it++)
					tmp.push_back(*it);
				for (; it < end(); it++)
					tmp.push_back(*it);
				*this = tmp;
			}
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void clear();
			void swap (vector& x);

			allocator_type get_allocator() const;
	};

	#include "vector.tpp"
} // namespace ft
	

#endif