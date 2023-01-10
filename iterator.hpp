/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:24:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/09 21:43:53 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITERATOR_HPP
# define	ITERATOR_HPP

# include <cstddef>

namespace ft
{
	template <class T>
  	class iterator
	{
		public:
    		typedef T         		value_type;
    		typedef ptrdiff_t		difference_type;
    		typedef value_type*   	pointer;
    		typedef value_type& 	reference;	
		private:
    		T* _m_ptr;	
		public:
			//iterator() = default; //tanrja3 l hadi
			iterator(T* m_ptr) : _m_ptr(m_ptr){}
    		T& operator*(){
				return *_m_ptr;}
    		iterator& operator++(){
				_m_ptr++;
				return *this;}
    		iterator operator++(int){
				++_m_ptr;
				return *this;}
    		iterator& operator--(){
				_m_ptr--;
				return *this;}
    		iterator operator--(int){
				--_m_ptr;
				return *this;}
    		iterator& operator+=(difference_type n){
				return iterator<T>(_m_ptr + n);}
    		iterator& operator-=(difference_type n){
				return iterator<T>(_m_ptr - n);}
			iterator operator+(difference_type n) { //const{
				return iterator<T>(_m_ptr + n);}
    		iterator operator-(difference_type n) { //const{
				return iterator<T>(_m_ptr - n);}
	   		difference_type  operator-(const iterator& other){ //const{
				return _m_ptr - other._m_ptr;} 

    		bool operator==(const iterator& other) const{
				return (_m_ptr == other._m_ptr);}
    		bool operator!=(const iterator& other) const{
				return !(*this == other);}
    		bool operator<(const iterator& other) const{
				return (_m_ptr < other._m_ptr);}
    		bool operator<=(const iterator& other) const{
				return (_m_ptr <= other._m_ptr);}
    		bool operator>(const iterator& other) const{
				return (other < *this);}
    		bool operator>=(const iterator& other) const{
				return (other <= *this);}
  	};
}
#endif