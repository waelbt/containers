/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:56 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/05 19:06:27 by waboutzo         ###   ########.fr       */
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
			typedef size_t 											size_type;
		private:
			pointer			_begin;
			pointer			_end;
			pointer			_end_cap;
			allocator_type	_alloc;
			size_type		size;
	};
}
#endif