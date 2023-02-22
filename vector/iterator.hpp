/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:24:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:38:37 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITERATOR_HPP
# define	ITERATOR_HPP

# include <cstddef>
# include "../utility/extra.hpp"
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
			typedef const value_type&				const_reference;
			typedef const value_type*				const_pointer;
			typedef std::random_access_iterator_tag iterator_category;
		protected:
    		pointer _m_ptr;	
		public:
			iterator(): _m_ptr(pointer()){}
			iterator(pointer m_ptr) : _m_ptr(m_ptr){}
			iterator(const iterator& obj) : _m_ptr(obj._m_ptr){}
			pointer get() const{return _m_ptr;}
			operator iterator<const value_type>(){
        		return iterator<const value_type>(_m_ptr);}
			const_pointer operator->() const { return _m_ptr; }
			pointer operator->()  { return _m_ptr; }
			iterator& operator=(const iterator& obj){
				_m_ptr = obj._m_ptr;
				return *this;}
    		reference operator*(){
				return *_m_ptr;}
			const_reference operator* () const{
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
			iterator operator+(difference_type n) const {
				return _m_ptr + n;}
    		iterator operator-(difference_type n) const{ 
				return _m_ptr - n;}
			template <class U>
	   		difference_type  operator-(const iterator<U>& other) const{ 
				return _m_ptr - other.get();} 
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
	
} // namespace ft
#endif