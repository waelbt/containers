/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:56 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/06 22:01:54 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_HPP
# define	VECTOR_HPP

# include <iostream>

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

		public:
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
			for(pointer i = _begin; i < _end; i++)
				_alloc.destroy(i);
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
		(void )n;
		(void )val;
		//i will implement inserte or erase first
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
		return *_end;
	}

	template < class T, class Alloc>
	typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const{
		return *_end;
	}

	template < class T, class Alloc>
	void vector<T, Alloc>::assign (size_type n, const value_type& val){
		for (pointer i = _begin; i < _end; i++){
			_alloc.destroy(i);}
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
	vector<T, Alloc>::~vector(){
		for(pointer i = _begin; i < _end; i++)
			_alloc.destroy(i);
		_alloc.deallocate(_begin, this->capacity());
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