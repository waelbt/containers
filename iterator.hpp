/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:24:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/13 08:22:21 by waboutzo         ###   ########.fr       */
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
			iterator operator[](difference_type n) {
				return _m_ptr + n; }
			iterator operator[](difference_type n) const{
				return _m_ptr + n;}
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
    	return (it +n) ;}
	template <class T>
	iterator<T> operator-(ptrdiff_t n, iterator<T>  const& it){
    	return (it - n) ;}
	template<typename T>
	std::ostream& operator<<(std::ostream& os, iterator<T> it) {
    	os << *it;
    return os;
	}

} // namespace ft
#endif