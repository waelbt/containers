/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:41:43 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/12 19:53:30 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITERATOR_TRAITS_HPP
# define	ITERATOR_TRAITS_HPP


# include "iterator.hpp"
# include "tools.hpp"

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


// removed 
// template<class T>
// struct iterator_traits<const T*>
// {
//     typedef ptrdiff_t difference_type;
//     typedef T value_type;
//     typedef const T* pointer;
//     typedef const T& reference;
//     typedef std::random_access_iterator_tag iterator_category;
// };

#endif
