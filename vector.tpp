/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 09:03:46 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/18 01:13:34 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		VECTOR_TPP
# define	VECTOR_TPP


			/******* constructors ************/
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

			/******* Assignment operator ************/

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

			/******* Capacity ************/
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
	return (ft::is_char<T>::value) ? (_alloc.max_size() / 2) : _alloc.max_size();
}
	
template < class T, class Alloc>
void vector<T, Alloc>::resize (size_type n, value_type val){
	if (n > this->capacity())
		this->reserve(n);
	if (n < this->size()){
		for (size_type i = this->size(); i > n; i--)
			_alloc.destroy(--_end);
	}
	else if (n > this->size()){
		for (size_type i = this->size(); i < n; i++)
		{
			_alloc.construct(_end++, val);
		}
	}
}

template < class T, class Alloc>
bool vector<T, Alloc>::empty() const{
	return !(_end - _begin);
}

template < class T, class Alloc>
void vector<T, Alloc>::reserve (size_type n){
	if (n > capacity())
	{
		size_type size = this->size();
		pointer new_beg = _alloc.allocate(n);
		for (size_type i = 0; i < size; i++)
		{
			_alloc.construct(new_beg + i, *(_begin + i));
			_alloc.destroy(_begin + i);
		}
		if (_begin)
			this->_alloc.deallocate(_begin, capacity());
		_begin = new_beg;
		_end = new_beg + size;
		_end_cap = new_beg + n;
	}
}
			/******* Element access ************/
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


			/******* Modifiers ************/
template < class T, class Alloc>
void vector<T, Alloc>::assign (size_type n, const value_type& val){
	this->clear();
	resize(n, val);
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
		_alloc.destroy(--_end);
}

template < class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
	vector<T, Alloc>::insert(iterator position, const value_type& val)
{
	difference_type distance;
	pointer		it;

	distance = position - begin();
	if (!capacity())
		reserve(1);
	if (size() == capacity())
		reserve(capacity() * 2);
	_alloc.construct(_end++, val);
	for (it = _end - 1; it > (_begin + distance); it--)
		std::swap(*it, *(it - 1));
	return (begin() + distance);
}


template < class T, class Alloc>
void vector<T, Alloc>::insert (ft::vector<T, Alloc>::iterator position,
	size_type n, const value_type& val)
{
	difference_type distance;
	size_type		size;
	pointer		tmp;
	
	distance = position - begin();
	size = this->size();
	if (size + n > capacity())
	{
		if (size + n < (capacity() * 2))
			reserve(size + n);
		else
			reserve(capacity() * 2);
	}
	resize(size + n, val);
	tmp = _end;
	for (difference_type i = size - 1; i >= distance; i--)
		std::swap(*(begin() + i),*(--tmp));
}

template < class T, class Alloc>
typename ft::vector<T, Alloc>::iterator
	vector<T, Alloc>::erase (ft::vector<T, Alloc>::iterator position)
{
	for (iterator it = position; it < end() - 1; it++)
		*it = *(it + 1);
	pop_back();
	return position;
}

template < class T, class Alloc>
typename ft::vector<T, Alloc>::iterator vector<T, Alloc>::erase(
	ft::vector<T, Alloc>::iterator first, ft::vector<T, Alloc>::iterator last){
	difference_type distance = std::distance(first, last);
	difference_type de = std::distance(begin(), first);
	iterator tmp = first;
	for (iterator it = last; it != end(); it++)
		*(first++) = *it;
	for(difference_type i = 0; i < distance / 2;i++)
	{
		_alloc.destroy(--_end);
		_alloc.destroy(--_end);
	}
	if(distance % 2)
		_alloc.destroy(--_end);
	return _begin + de;
}

template < class T, class Alloc>
void vector<T, Alloc>::clear(){
	size_type half_size;
	size_type odd;
	pointer tmp = _begin;

	half_size = this->size() / 2;
	odd = this->size() % 2;
	for (size_type i = 0; i < half_size; i++)
	{
		_alloc.destroy(_begin++);
		_alloc.destroy(--_end);
	}
	if (odd)
		_alloc.destroy(_begin);
	_begin = tmp;
	_end = tmp;
}

template < class T, class Alloc>
void vector<T, Alloc>::swap (vector& x){
	std::swap(_begin, x._begin);
	std::swap(_end, x._end);
	std::swap(_end_cap, x._end_cap);
	std::swap(_alloc, x._alloc);
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
	x.swap(y);
}
			/******* Iterators ************/
template < class T, class Alloc>
typename ft::vector<T, Alloc>::iterator vector<T, Alloc>::begin(){
	return _begin;}

template < class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const{
	return _begin;}

template < class T, class Alloc>
typename ft::vector<T, Alloc>::iterator vector<T, Alloc>::end(){
	return _end;}

template < class T, class Alloc>
typename ft::vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const{
	return _end;}

			/******* Allocater ************/
template < class T, class Alloc>
typename vector<T, Alloc>::allocator_type vector<T, Alloc>::get_allocator() const{
	return _alloc;
}

			/******* destructor ************/
template < class T, class Alloc>
vector<T, Alloc>::~vector(){
	this->clear();
	if (_begin)
		_alloc.deallocate(_begin, this->capacity());
	_begin = NULL;
	_end = NULL;
	_end_cap = NULL;
}

#endif