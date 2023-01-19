/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:56 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/19 15:44:25 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_HPP
# define	VECTOR_HPP

# include <iostream>
// # include "type_traits.hpp"
# include <vector>

#include <stack>
# include <type_traits>
# include "iterator.hpp"

# define SFINA(X) typename ft::enable_if<!ft::is_integral<X>::value, X>::type *  = 0
# define IS_INPUT(X) ((ft::is_same<typename X, std::input_iterator_tag>::value) ? (1) : (0))

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
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), SFINA(InputIterator)) : _begin(NULL), _end(NULL), _end_cap(NULL),_alloc(alloc){
				if (!IS_INPUT(iterator_traits<InputIterator>::iterator_category))
				{
					difference_type size;

					size = std::distance(first, last);
					_begin = _alloc.allocate(size);
					_end = _begin + size;
					_end_cap = _end;
					for(pointer i = _begin; i < _end; i++)
						_alloc.construct(i, *(first++));
				}
				else
				{
					for(InputIterator i = first; i != last; i++)
						push_back(*i);
				}
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
  			void assign (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value , InputIterator>::type last){
				this->clear();
				if (!IS_INPUT(iterator_traits<InputIterator>::iterator_category))
				{
					size_type size;

					size = std::distance(first, last);
					if(size > capacity())
					{
						if (_begin)
							this->_alloc.deallocate(_begin, capacity());
						_begin = _alloc.allocate(size);
						_end_cap = _begin + size;
					}
					_end = _begin + size;
					for(pointer i = _begin; i < _end; i++)
						_alloc.construct(i, *(first++));
				}
				else
				{
					for(InputIterator i = first; i != last; i++)
						push_back(*i);
				}
			}
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InptIter>
    		void insert (iterator position, InptIter first,InptIter last, SFINA(InptIter))
			{
				iterator tmp;

				if (!IS_INPUT(iterator_traits<InptIter>::iterator_category)){
					difference_type start = position - begin();
					difference_type range = std::distance(first, last);
					size_type		previous_size = size();

					if (previous_size + range > capacity())
						reserve(capacity() * 2);
					resize(previous_size + range);
					tmp = end();
					for (difference_type i = previous_size - 1; i >= start; i--)
						*(--tmp) = *(begin() + i);
					InptIter tmp2 = first;
					for (difference_type it = start; it < range + start; it++)
						*(begin() + it) = *(tmp2++);}
				else
				{
					tmp = position;
					for (InptIter it = first; it != last; it++){
						tmp = insert(tmp, *it);
						tmp++;}
				}
			}
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void clear();
			void swap (vector& x);

			allocator_type get_allocator() const;
	};
	template <class T, class Alloc> 
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	}
	
	template <class T, class Alloc> 
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	}
	
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(rhs < lhs);
	}
	
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return rhs < lhs;
	}
	
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs < rhs);
	}
	#include "vector.tpp"
} // namespace ft


#endif