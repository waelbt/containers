/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:45:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/14 09:08:19 by waboutzo         ###   ########.fr       */
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
			typedef		Key													key_type;
			typedef		T 													mapped_type;
			typedef		ft::pair<const key_type, mapped_type>				value_type;
			typedef		Compare												key_compare;
			typedef		Alloc												allocator_type;
			typedef		typename allocator_type::reference					reference;
			typedef		typename allocator_type::const_reference			const_reference;
			typedef		typename allocator_type::pointer					pointer;
			typedef		typename allocator_type::const_pointer				const_pointer;

			// const_iterator
			// reverse_iterator
			// const_reverse_iterator
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type 			size_type;
			class 	value_compare : ft::binary_function<value_type, value_type, bool>
			{   
				friend class map;
				protected:
			  		key_compare comp;
					value_compare (key_compare c) : comp(c) {}
				public:
					value_compare () : comp() {}
			  		bool operator() (const value_type& x, const value_type& y) const
			  		{
			    		return comp(x.first, y.first);
			  		}
			};
			typedef 	TREE<value_type, value_compare, allocator_type> tree_type;
		private:
			tree_type		_tree;
			key_compare		_comp;
			allocator_type _alloc;
		public:
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _comp(comp), _alloc(alloc) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(), _comp(comp), _alloc(alloc)
			{
				for (; first != last; first++)
					_tree.insert(*first);
			}
			map (const map& x) : _tree(x._tree), _comp(x._comp), _alloc(x._alloc)
			{				
			}
			map& operator= (const map& x)
			{
				_tree = x._tree;
				_comp = x._comp;
			}
			bool empty() const
			{
				return _tree.empty();
			}
			size_type size() const
			{
				return _tree.size();
			}
			size_type max_size() const
			{
				return _tree.max_size();
			}
			mapped_type& operator[] (const key_type& k)
			{
				
			}
			~map(){}
	};	
} // namespace ft

#endif