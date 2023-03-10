/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:29:51 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:41:09 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
namespace ft
{
	/******** reverse_iterator *******/
	template <class Iterator>
  	class reverse_iterator : public Iterator
	{
		public:
			typedef Iterator iterator_type;
  			typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
  			typedef typename ft::iterator_traits<Iterator>::reference reference;
  			typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		protected:
			Iterator _iter_adapt;
		public:
			reverse_iterator() : _iter_adapt(Iterator()) {}
			explicit reverse_iterator(Iterator obj) : _iter_adapt(obj){}
			template <class T>
			reverse_iterator(const reverse_iterator<T>& other) : _iter_adapt(other.base()) {}
			reverse_iterator& operator=(const reverse_iterator& other)
			{
     			_iter_adapt = other._iter_adapt;
        		return *this;}
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
} //namespace ft


#endif