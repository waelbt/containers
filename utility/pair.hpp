/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:57:53 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:40:50 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
		/*pair*/
	template<class T1,class T2>
	struct pair
	{
			/* Member types */
		typedef T1		first_type;
		typedef T2 		second_type;
			/* Member objects */
		T1		first;
		T2		second;
			/* constructor */
		pair() : first(T1()), second(T2()){}
		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second){}
		pair (const first_type& a, const second_type& b) : first(a), second(b){}
			/*Assignment operator*/
		pair& operator= (const pair& pr){
			first = pr.first;
			second = pr.second;
			return *this;
		}
	};
	template <class T1, class T2>
  	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
  	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
  	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
  	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
  	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
 	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
			/*make pair*/
	template <class T1,class T2>
  	pair<T1,T2> make_pair (T1 x, T2 y){
    	return ( pair<T1,T2>(x,y) );
	}
} // namespace ft

#endif