/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:40:20 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/13 02:42:39 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESERVE_ITERATOR_HPP
# define RESERVE_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <class Iterator>
  	class reverse_iterator : public Iterator
	{
		public:
			typedef Iterator iterator_type;
  			typedef typename iterator_traits<Iterator>::difference_type difference_type;
  			typedef typename iterator_traits<Iterator>::reference reference;
  			typedef typename iterator_traits<Iterator>::pointer pointer;
		protected:
			Iterator _itertor_adaptor;
		public:
			reverse_iterator(){}
			explicit reverse_iterator(const Iterator& obj) : _itertor_adaptor(obj){}
			reverse_iterator(const reverse_iterator& obj) : _itertor_adaptor(obj._itertor_adaptor){}
			reverse_iterator<Iterator>& operator=(const reverse_iterator<Iterator>& other)
			{
     			_itertor_adaptor = other._itertor_adaptor;
        		return *this;
    		}
			Iterator base() const{return _itertor_adaptor;}
			operator Iterator() const { return base(); }
			operator reverse_iterator<Iterator>(){
        		return reverse_iterator<Iterator>(_itertor_adaptor);}
			reverse_iterator<Iterator>& operator++(){
				return reverse_iterator<Iterator>(_itertor_adaptor--);}
  			reverse_iterator<Iterator>  operator++(int){
				return reverse_iterator<Iterator>(--_itertor_adaptor);}
  			reverse_iterator<Iterator>& operator--(){
				return reverse_iterator<Iterator>(_itertor_adaptor++);}
  			reverse_iterator<Iterator>  operator--(int){
				return reverse_iterator<Iterator>(++_itertor_adaptor);}
			reverse_iterator<Iterator>  operator+ (difference_type n) const{
				reverse_iterator<Iterator>(_itertor_adaptor + n);}
  			reverse_iterator<Iterator>& operator+=(difference_type n){
				_itertor_adaptor += n;
				return (*this);}
  			reverse_iterator<Iterator>  operator- (difference_type n) const{
				reverse_iterator<Iterator>(_itertor_adaptor - n);}
  			reverse_iterator<Iterator>& operator-=(difference_type n){
				_itertor_adaptor -= n;
				return (*this);}
	};
} // namespace ft

# endif