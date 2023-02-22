/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:45:29 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:39:41 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "../red-black-tree/tree.hpp"
# include "../utility/less.hpp"
# include "../utility/pair.hpp"
# include "../utility/eqaul_and_lexico_comp.hpp"

namespace ft
{
	template < class Key,                                     		// map::key_type
        class T,                                       		// map::mapped_type
        class Compare = ft::less<Key>,                    	// map::key_compare
        class Alloc = std::allocator<ft::pair<const Key,T> >   	// map::allocator_type
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
			typedef 	typename allocator_type::difference_type			difference_type;
			typedef 	typename allocator_type::size_type 					size_type;
			class 		value_compare : ft::binary_function<value_type, value_type, bool>
			{   
				// friend class map;
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
			typedef 	ft::TREE<value_type, value_compare, allocator_type> tree_type;
			typedef 	typename tree_type::iterator 						iterator;
			typedef 	typename tree_type::const_iterator 					const_iterator;
			typedef 	typename tree_type::reverse_iterator 				reverse_iterator;
			typedef 	typename tree_type::const_reverse_iterator			const_reverse_iterator;
		
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
				{
					_tree.insert(*first);
				}
			}

			map (const map& x) : _tree(x._tree), _comp(x._comp), _alloc(x._alloc)
			{				
			}

			map& operator= (const map& x)
			{
				_tree = x._tree;
				_comp = x._comp;
				return *this;
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

			void clear()
			{
				_tree.clear();
			}

			iterator begin()
			{
				return _tree.begin();
			}

			iterator end()
			{
				return _tree.end();
			}

			const_iterator begin() const
			{
				return _tree.begin();
			}

			const_iterator end() const
			{
				return _tree.end();
			}

			reverse_iterator rbegin()
			{
				return _tree.rbegin();
			}

			reverse_iterator rend()
			{
				return _tree.rend();
			}

			const_reverse_iterator rbegin() const
			{
				return _tree.rbegin();
			}

			const_reverse_iterator rend() const
			{
				return _tree.rend();
			}

			iterator find (const key_type& k)
			{
 				return _tree.search(ft::make_pair(k, mapped_type()));
			}

			const_iterator find (const key_type& k) const
			{
				return _tree.search(ft::make_pair(k, mapped_type()));
			}


			ft::pair<iterator,bool> insert (const value_type& val)
			{
				iterator tmp = find(val.first);

				if (tmp != end())
					return ft::make_pair(tmp, false);
				return ft::make_pair(_tree.insert(val), true);
			}

			iterator insert (iterator position, const value_type& val)
			{
				(void) position;
				return (insert(val).first);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (;first!=last;first++)
					insert(*first);
			}

			void erase (iterator position)
			{
				_tree.deletion((*position));
			}
			
			size_type erase (const key_type& k)
			{
				iterator it = find(k);

				if (it != end())
				{
					erase(it);
					return true;
				}
				return false;
			}
			
			void erase (iterator first, iterator last)
			{
				iterator tmp;

				while( first != last)
				{
					tmp = first++;
					erase(tmp);
				}
			}


			mapped_type& at (const key_type& k)
			{
				iterator it = find(k);

				if (it == end())
					throw std::out_of_range("map");
				return it->second;
			}

			const mapped_type& at (const key_type& k) const
			{
				const_iterator it = find(k);

				if (it == end())
					throw std::out_of_range("map");
				return it->second;
			}


			mapped_type& operator[] (const key_type& k)
			{
				iterator it = find(k);

				if (it != end())
					return it->second;
				return insert(ft::make_pair(k, mapped_type())).first->second;
			}

			void swap (map& x)
			{
				_tree.swap(x._tree);
				ft::swap(_comp, x._comp);
				ft::swap(_alloc, x._alloc);
			}

			key_compare key_comp() const
			{
				return _comp;
			}

			value_compare value_comp() const
			{
				return value_compare();
			}

			size_type count (const key_type& k) const
			{
				const_iterator it = find(k);

				if (it != end())
					return true;
				return false;
			}

			iterator lower_bound (const key_type& k)
			{
				return 	_tree.lower_bound(ft::make_pair(k, mapped_type()));
			}

			const_iterator lower_bound (const key_type& k) const
			{
				return 	_tree.lower_bound(ft::make_pair(k, mapped_type()));
			}


			iterator upper_bound (const key_type& k)
			{
				return 	_tree.upper_bound(ft::make_pair(k, mapped_type()));
			}
			
			const_iterator upper_bound (const key_type& k) const
			{
				return 	_tree.upper_bound(ft::make_pair(k, mapped_type()));
			}

			pair<const_iterator,const_iterator>
			equal_range (const key_type& k) const
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			pair<iterator,iterator>
			equal_range (const key_type& k)
			{
				return ft::make_pair(lower_bound(k), upper_bound(k));
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}
			~map(){}
	};
	template< class Key, class T, class Compare, class Alloc >
	void swap (map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y){
		x.swap(y);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y )
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<  ( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs ){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator<= ( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs ){
		return !(rhs < lhs);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>  ( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs ){
		return (rhs < lhs);
	}
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator>= ( const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs ){
		return !(lhs < rhs);
	}
} // namespace ft

#endif