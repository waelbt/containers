/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:56 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/08 19:06:08 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_HPP
# define	VECTOR_HPP

# include <iostream>
# include "tools.hpp"
# include <vector>

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
			typedef	typename std::vector<T>::iterator							iterator; // the vector itertor is just temporary i will remove it 
			typedef	typename std::vector<T>::const_iterator						const_iterator; // the vector itertor is just temporary i will remove it 
			typedef typename std::reverse_iterator<iterator>					reverse_iterator; //tmp
			typedef typename std::reverse_iterator<const_iterator>				const_reverse_iterator; //tmp
			typedef typename std::iterator_traits<iterator>::difference_type	difference_type; //tmp
			typedef size_t 														size_type;

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
         	// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);
			
			vector& operator= (const vector& x);

			~vector();

			// iterator begin();
			// const_iterator begin() const;
			// iterator end();
			// const_iterator end() const;

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

			// template <class InputIterator>
  			// void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);
			void push_back (const value_type& val);
			void pop_back();
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
			// not all the allocator protected
			this->clear();
			if (x.size() > this->capacity())
			{
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
	size_t vector<T, Alloc>::capacity() const{
		return (_end_cap - _begin);
	}
	
	template < class T, class Alloc>
	size_t vector<T, Alloc>::size() const{
		return (_end - _begin);;
	}
	
	template < class T, class Alloc>
	size_t vector<T, Alloc>::max_size() const{
		return  (SIZE_MAX / sizeof(T));
	}
	
	template < class T, class Alloc>
	void vector<T, Alloc>::resize (size_type n, value_type val){
		if (n > (this->capacity() * 2))
			this->reserve(n);
		if (n < this->size()){
			for (size_type i = n; i < this->size(); i++)
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
			_end_cap = _begin + n;
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
		if (this->capacity() < n)
		{
			_alloc.deallocate(_begin, this->capacity());
			_begin = _alloc.allocate(n);
			_end_cap = _begin + n;
		}
		_end = _begin + n;
		for (pointer i = _begin; i < _end; i++){
			_alloc.construct(i, val);}
	}
	
	template < class T, class Alloc>
	typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const{
		return _alloc;
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::push_back (const value_type& val){
		//std::cout << "std : " << this->size() << " " << this->capacity() << std::endl; 
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
			_alloc.destroy(_end);
			_end--;
		}
	}
	template < class T, class Alloc>
	void vector<T, Alloc>::clear(){
		for(pointer i = _begin; i < _end; i++)
			_alloc.destroy(i);
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::swap (vector& x){
		ft::swap(_begin, x._begin);
		ft::swap(_end, x._end);
		ft::swap(_end_cap, x._end_cap);
		ft::swap(_alloc, x._alloc);
	}

	template < class T, class Alloc>
	vector<T, Alloc>::~vector(){
		if (_begin)
		{
			this->clear();
			_alloc.deallocate(_begin, this->capacity());
		}
	}
}
	// template < class T, class Alloc>
	// typename vector<T, Alloc>::iterator vector<T, Alloc>::begin(){
	// 	return iterator(_begin);
	// }

	// template < class T, class Alloc>
	// typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const{
	// 	return const_iterator(_begin);
	// }
	
	// template < class T, class Alloc>
	// typename vector<T, Alloc>::iterator vector<T, Alloc>::end(){
	// 	return iterator(_end);
	// }

	// template < class T, class Alloc>
	// typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const{
	// 	return const_iterator(_end);
	// }
	
#endif