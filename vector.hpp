/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:56 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/10 03:02:45 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_HPP
# define	VECTOR_HPP

# include <iostream>
# include "tools.hpp"
# include <vector>
# include "iterator.hpp"
# include "is_integral.hpp"

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
			typedef	typename std::vector<T>::const_iterator						const_iterator; // the vector itertor is just temporary i will remove it 
			typedef typename std::reverse_iterator<iterator>					reverse_iterator; //tmp
			typedef typename std::reverse_iterator<const_iterator>				const_reverse_iterator; //tmp
			// typedef typename std::iterator_traits<iterator>::difference_type	difference_type; //tmp
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
			// template <class InputIterator>
         	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc){
			// 	difference_type size;
				
			// 	size = last - first;
			// 	_begin = _alloc.allocate(size);
			// 	_end = _begin + size;
			// 	_end_cap = _end;
			// 	for(pointer i = _begin; i < _end; i++)
			// 		_alloc.construct(i, *(first++));
			// }
			vector (const vector& x);
			
			vector& operator= (const vector& x);

			~vector();

			iterator begin();
			//const_iterator begin() const;
			iterator end();
			// const_iterator end() const;

			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			
			//reverse_iterator rend();
			//const_reverse_iterator rend() const;

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
			void clear();
			void swap (vector& x);

			allocator_type get_allocator() const;
	};

	template < class T, class Alloc>
	vector<T, Alloc>::vector (const Alloc& alloc) : _begin(NULL), _end(NULL), _end_cap(NULL), _alloc(alloc){}

	template < class T, class Alloc>
	vector<T, Alloc>::vector (size_type n, const value_type& val, const allocator_type& alloc)
	: _alloc(alloc){
		_begin = _alloc.allocate(n);
		_end = _begin + n;
		_end_cap = _end;
		for(pointer i = _begin; i < _end; i++)
			_alloc.construct(i, val);
	}
	template < class T, class Alloc>
	vector<T, Alloc>::vector (const vector& x) : _begin(NULL), _end(NULL), _end_cap(NULL), _alloc(x._alloc){
		*this = x;
	}
	template < class T, class Alloc>
	vector<T, Alloc>&  vector<T, Alloc>::operator= (const vector& x){
		pointer		tmp;
	
		if (this != &x)
		{
			this->clear();
			if (x.size() > this->capacity())
			{
				if (_begin)
					_alloc.deallocate(_begin, this->capacity());
				_begin = _alloc.allocate(x.capacity());
				_end_cap = _begin + x.capacity();
			}
			_end = _begin + x.size();
			tmp = x._begin;
			for(pointer i = _begin; i < _end; i++)
				_alloc.construct(i, *(tmp++));
		}
		return *this;
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const{
		return (_end_cap - _begin);
	}
	
	template < class T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const{
		return (_end - _begin);;
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const{
		if(ft::is_char<T>::value)
			return _alloc.max_size() / 2;
		return _alloc.max_size();
	}
	
	template < class T, class Alloc>
	void vector<T, Alloc>::resize (size_type n, value_type val){
		if (n > (this->capacity() * 2))
			this->reserve(n);
		if (n < this->size()){
			for (size_type i = this->size(); i > n; i--)
				this->pop_back();}
		else if (n > this->size()){
			for (size_type i = this->size(); i < n; i++)
				this->push_back(val);}
		_end = _begin + n;
	}

	template < class T, class Alloc>
	bool vector<T, Alloc>::empty() const{
		return !(_end - _begin);
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::reserve (size_type n){
		if (n > this->capacity())
		{
			vector<T, Alloc> tmp(*this);
			this->~vector();
			_begin = _alloc.allocate(n);
			_end = _begin;
			_end_cap = _begin + n;
			if (tmp.size())
				*this = tmp;
		}
	}
	
	template < class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::operator[] (size_type n){
		return *(_begin + n);
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::operator[] (size_type n) const{
		return *(_begin + n);
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::at (size_type n){
		if (n >= this->size())
			throw std::out_of_range("vector");
		return (*this)[n];
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::at (size_type n) const{
		if (n >= this->size())
			throw std::out_of_range("vector");
		return (*this)[n];
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::front(){
		return *_begin;
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const{
		return *_begin;
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::reference vector<T, Alloc>::back(){
		return *(_end - 1);
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const{
		return *(_end - 1);
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::assign (size_type n, const value_type& val){
		this->clear();
		for (size_t i = 0; i != n; i++)
			push_back(val);
	}
	
	template < class T, class Alloc>
	typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const{
		return _alloc;
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::push_back (const value_type& val){
		if (!this->capacity())
			this->reserve(1);
		else if (this->size() == this->capacity())
			this->reserve(this->capacity() * 2);
		_alloc.construct(_end, val);
		_end++;
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::pop_back (){
		if (this->size())
		{
			_alloc.destroy(_end - 1);
			_end--;
		}
	}
	
	template < class T, class Alloc>
	typename ft::vector<T, Alloc>::iterator
		vector<T, Alloc>::insert(ft::vector<T, Alloc>::iterator position, const value_type& val)
	{
		vector<T, Alloc> tmp;
		ft::vector<T, Alloc>::iterator it;
		int i = 0;

		for (it = begin(); it != position; it++)
		{
			i++;
			tmp.push_back(*it);
		}
		tmp.push_back(val);
		for (; it < end(); it++)
			tmp.push_back(*it);
		*this = tmp;
		return iterator(_begin + i);
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::insert (ft::vector<T, Alloc>::iterator position,
		size_type n, const value_type& val)
	{
		vector<T, Alloc> tmp;
		ft::vector<T, Alloc>::iterator it;
	
		if (n >= max_size())
			throw std::length_error("vector");
		for (it = begin(); it != position; it++)
			tmp.push_back(*it);
		for(size_t i = 0 ; i < n; i++)
			tmp.push_back(val);
		for (; it < end(); it++)
			tmp.push_back(*it);
		*this = tmp;
	}
	
	template < class T, class Alloc>
	void vector<T, Alloc>::clear(){
		while (this->size())
			this->pop_back();
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::swap (vector& x){
		ft::swap(_begin, x._begin);
		ft::swap(_end, x._end);
		ft::swap(_end_cap, x._end_cap);
		ft::swap(_alloc, x._alloc);
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}

	template < class T, class Alloc>
	typename ft::vector<T, Alloc>::iterator vector<T, Alloc>::begin(){
		return iterator(_begin);
	}

	// template < class T, class Alloc>
	// typename std::vector<T>::const_iterator vector<T, Alloc>::begin() const{
	// 	return std::vector<T>::const_iterator(_begin);
	// }
	
	template < class T, class Alloc>
	typename ft::vector<T, Alloc>::iterator vector<T, Alloc>::end(){
		return iterator(_end);
	}
	
	// template < class T, class Alloc>
	// typename std::vector<T>::const_iterator vector<T, Alloc>::end() const{
	// 	return std::vector<T>::const_iterator(_end);
	// }

	template < class T, class Alloc>
	vector<T, Alloc>::~vector(){
		this->clear();
		if (_begin)
			_alloc.deallocate(_begin, this->capacity());
	}
}
	
#endif