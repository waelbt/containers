/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:31:02 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:40:23 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft
{
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
} // namespace ft



#endif