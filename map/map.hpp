/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:45:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/14 05:21:32 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "tree.hpp"
# include "../utility/less.hpp"
# include "../utility/pair.hpp"

namespace ft
{
	template < class Key,                                     		// map::key_type
        class T,                                       		// map::mapped_type
        class Compare = ft::less<Key>,                    	// map::key_compare
        class Alloc = std::allocator<pair<const Key,T> >   	// map::allocator_type
        >
	class map
	{
		public :
			typedef	Key											key_type;
			typedef	T 											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			// iterator
			// const_iterator
			// reverse_iterator
			// const_reverse_iterator
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
			class 	value_compare : ft::binary_function<value_type, value_type, bool>
			{   
			  	// friend class map;
				protected:
			  		key_compare comp;
			  		value_compare (key_compare c) : comp(c) {}
				public:
			  		bool operator() (const value_type& x, const value_type& y) const
			  		{
			    		return comp(x.first, y.first);
			  		}
			};
	};	
} // namespace ft

#endif