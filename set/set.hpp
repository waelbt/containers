/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:24:59 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/23 19:15:15 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../red-black-tree/tree.hpp"
# include "../utility/less.hpp"
# include "../utility/pair.hpp"
# include "../utility/eqaul_and_lexico_comp.hpp"
# include "../utility/iterator_traits.hpp"
# include "../utility/extra.hpp"


namespace ft
{
	template < class T,  class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public :
			typedef		T													key_type;
			typedef		key_type											value_type;
			typedef		Compare												key_compare;
			typedef		Compare												value_compare;
			typedef		Alloc												allocator_type;
			typedef		typename allocator_type::reference					reference;
			typedef		typename allocator_type::const_reference			const_reference;
			typedef		typename allocator_type::pointer					pointer;
			typedef		typename allocator_type::const_pointer				const_pointer;
			typedef 	typename allocator_type::difference_type			difference_type;
			typedef 	typename allocator_type::size_type 					size_type;
		private:
			typedef 	ft::TREE<value_type, key_compare, allocator_type> 	tree_type;
		public:
			typedef 	typename tree_type::iterator 						iterator;
			typedef 	typename tree_type::const_iterator 					const_iterator;
			typedef 	typename tree_type::reverse_iterator 				reverse_iterator;
			typedef 	typename tree_type::const_reverse_iterator			const_reverse_iterator;
	
			tree_type		_tree;
			key_compare		_comp;
			allocator_type _alloc;
		public:
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(), _comp(comp), _alloc(alloc) {}
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(), _comp(comp), _alloc(alloc)
			{
				for (; first != last; first++)
				{
					_tree.insert(*first);
				}
			}
			set (const set& x) : _tree(x._tree), _comp(x._comp), _alloc(x._alloc)
			{				
			}
			set& operator= (const set& x)
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

			iterator find (const value_type& k)
			{
 				return _tree.search(k);
			}

			const_iterator find (const value_type& k) const
			{
				return _tree.search(k);
			}


			ft::pair<iterator,bool> insert (const value_type& val)
			{
				iterator tmp = find(val);

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
			
			size_type erase (const value_type& k)
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


			value_type& at (const value_type& k)
			{
				iterator it = find(k);

				if (it == end())
					throw std::out_of_range("set");
				return it->second;
			}

			const value_type& at (const value_type& k) const
			{
				const_iterator it = find(k);

				if (it == end())
					throw std::out_of_range("set");
				return it->second;
			}

			void swap (set& x)
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
				return _comp;
			}

			size_type count (const value_type& k) const
			{
				const_iterator it = find(k);

				if (it != end())
					return true;
				return false;
			}

			iterator upper_bound (const value_type& val) 
			{
				return _tree.upper_bound(val);
			}

			iterator lower_bound (const value_type& val) 
			{
				return _tree.lower_bound(val);
			}

			pair<iterator,iterator> equal_range (const value_type& val)  
			{
				return ft::make_pair(lower_bound(val), upper_bound(val));
			}

			const_iterator upper_bound (const value_type& val) const
			{
				return _tree.upper_bound(val);
			}

			const_iterator lower_bound (const value_type& val) const
			{
				return _tree.lower_bound(val);
			}

			pair<const_iterator,const_iterator> equal_range (const value_type& val) const
			{
				return ft::make_pair(lower_bound(val), upper_bound(val));
			}

			allocator_type get_allocator() const
			{
				return _alloc;
			}
			~set(){}
	};
	template< class T, class Compare, class Alloc >
	void swap (set<T,Compare, Alloc>& x, set<T,Compare, Alloc>& y){
		x.swap(y);
	}
	template< class T, class Compare, class Alloc >
	bool operator==( const set<T,Compare, Alloc>& lhs, const set<T,Compare, Alloc>& rhs )
	{
		if (lhs.size() == rhs.size())
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		return false;
	}

	template< class T, class Compare, class Alloc >
	bool operator!=( const set<T,Compare, Alloc>& lhs, const set<T,Compare, Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator<  ( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template< class Key, class Compare, class Alloc >
	bool operator<= ( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ){
		return !(rhs < lhs);
	}
	
	template< class Key, class Compare, class Alloc >
	bool operator>  ( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ){
		return (rhs < lhs);
	}
	
	template< class Key, class Compare, class Alloc >
	bool operator>= ( const ft::set<Key, Compare, Alloc>& lhs, const ft::set<Key, Compare, Alloc>& rhs ){
		return !(lhs < rhs);
	}
}