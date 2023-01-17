/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:24:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/17 17:49:03 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITERATOR_HPP
# define	ITERATOR_HPP

# include <cstddef>
#include "type_traits.hpp"
#include <iostream>
namespace ft
{
				/*iterator traits*/
	template<class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
	

	template<class  T>
	struct iterator_traits<T*>
	{
    	typedef ptrdiff_t difference_type;
    	typedef typename ft::remove_cv<T>::type value_type;
    	typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
	};
				/*	iterator	*/
	template <class T>
  	class iterator
	{
		public:
    		typedef typename ft::remove_cv<T>::type value_type;
    		typedef ptrdiff_t						difference_type;
    		typedef T*   							pointer;
    		typedef T& 								reference;
			typedef std::random_access_iterator_tag iterator_category;
		protected:
    		pointer _m_ptr;	
		public:
			iterator(): _m_ptr(NULL){}
			iterator(pointer m_ptr) : _m_ptr(m_ptr){}
			iterator(const iterator& obj) : _m_ptr(obj._m_ptr){}
			pointer get() const{return _m_ptr;}
			operator iterator<const value_type>(){
        		return iterator<const value_type>(_m_ptr);}
			pointer operator->() const { return _m_ptr; }
			iterator& operator=(const iterator& obj){
				_m_ptr = obj._m_ptr;
				return *this;}
    		reference operator*(){
				return *_m_ptr;}
    		iterator& operator++(){
				_m_ptr++;
				return *this;}
    		iterator operator++(int){
				iterator tmp(*this);
				++_m_ptr;
				return tmp;}
    		iterator& operator--(){
				_m_ptr--;
				return *this;}
    		iterator operator--(int){
				iterator tmp(*this);
				--_m_ptr;
				return tmp;}
    		iterator& operator+=(difference_type n) {
				_m_ptr  += n;
				return *this;}
    		iterator& operator-=(difference_type n) {
				_m_ptr  -= n;
				return *this;}
			iterator operator+(difference_type n) const { //const{
				return _m_ptr + n;}
    		iterator operator-(difference_type n) const{ //const{
				return _m_ptr - n;}
	   		difference_type  operator-(const iterator& other) const{ //const{
				return _m_ptr - other._m_ptr;} 
			difference_type  operator+(const iterator& other) const{ //const{
				return _m_ptr + other._m_ptr;} 
			// reference operator[](difference_type n) {
			// 	return *this + n; }
			reference operator[](difference_type n) const{
				return _m_ptr[n];}
  	};

	template <class T, class U>
	bool operator==(const iterator<T>& iter1, const iterator<U>& iter2){
		return (iter1.get() == iter2.get());}

	template <class T, class U>
    bool operator!=(const iterator<T>& iter1, const iterator<U>& iter2){
		return !(iter1 == iter2);}
	
	template <class T, class U>
    bool operator<(const iterator<T>& iter1, const iterator<U>& iter2){
		return (iter1.get() < iter2.get());}

	template <class T, class U>
    bool operator<=(const iterator<T>& iter1, const iterator<U>& iter2){
		return (iter1.get() <= iter2.get());}
	
	template <class T, class U>
    bool operator>(const iterator<T>& iter1, const iterator<U>& iter2){
		return !(iter1 <= iter2);}

	template <class T, class U>
    bool operator>=(const iterator<T>& iter1, const iterator<U>& iter2){
		return !(iter1 < iter2);}
	template <class T>
	iterator<T> operator+(ptrdiff_t n, iterator<T>  const& it){
    	return (it + n) ;}
	template <class T>
	iterator<T> operator-(ptrdiff_t n, iterator<T>  const& it){
    	return (it - n) ;}
	template<typename T>
	std::ostream& operator<<(std::ostream& os, iterator<T> it) {
    	os << *it;
    return os;
	}

				/******** reverse_iterator *******/
	template <class Iterator>
  	class reverse_iterator : public Iterator
	{
		public:
			typedef Iterator iterator_type;
  			typedef typename iterator_traits<Iterator>::difference_type difference_type;
  			typedef typename iterator_traits<Iterator>::reference reference;
  			typedef typename iterator_traits<Iterator>::pointer pointer;
		protected:
			Iterator _iter_adapt;
		public:
			reverse_iterator() : _iter_adapt() {}
			explicit reverse_iterator(Iterator obj) : _iter_adapt(obj){}
			template <class T>
			reverse_iterator(const reverse_iterator<T>& other) : _iter_adapt(other.base()) {}
			template <class T>
			reverse_iterator& operator=(const reverse_iterator<T>& other)
			{
     			_iter_adapt = other.base();
        		return *this;}
			operator reverse_iterator<const Iterator>(){
        		return reverse_iterator<const Iterator>(_iter_adapt);}
			Iterator base() const {return _iter_adapt;} 
    		reference operator*() const {Iterator tmp = _iter_adapt; return *(--tmp);} 
    		pointer  operator->() const {return &(operator*());} 
    		reverse_iterator& operator++() {--_iter_adapt; return *this;} 
    		reverse_iterator  operator++(int) {reverse_iterator tmp(*this); --_iter_adapt; return tmp;} 
    		reverse_iterator& operator--() {++_iter_adapt; return *this;} 
    		reverse_iterator  operator--(int) {reverse_iterator tmp(*this); ++_iter_adapt; return tmp;} 
    		reverse_iterator  operator+ (difference_type n) const {return reverse_iterator(_iter_adapt - n);} 
    		reverse_iterator& operator+=(difference_type n) {_iter_adapt -= n; return *this;} 
    		reverse_iterator  operator- (difference_type n) const {return reverse_iterator(_iter_adapt + n);} 
    		reverse_iterator& operator-=(difference_type n) {_iter_adapt += n; return *this;} 
    		reference         operator[](difference_type n) const {return *(*this + n);}
	};

	template <class T>
	reverse_iterator<T> operator+(ptrdiff_t n, reverse_iterator<T>  const& it){
    	return it + n;}
	template <class T>
	reverse_iterator<T> operator-(ptrdiff_t n, reverse_iterator<T>  const& it){
    	return  it - n;}

	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
		return obj1.base() == obj2.base();}
	
	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
	    return obj1.base() > obj2.base();}
	
	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
	    return obj1.base() != obj2.base();}
	
	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
	    return obj1.base() < obj2.base();}
	
	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
	    return obj1.base() <= obj2.base();}
	
	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
	    return obj1.base() >= obj2.base();}

	template <class Iterator1, class Iterator2>
	ptrdiff_t operator-(const reverse_iterator<Iterator1>& obj1, const reverse_iterator<Iterator2>& obj2){
	    return obj2.base() - obj1.base();}
} // namespace ft
#endif