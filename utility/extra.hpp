/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:28:41 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:40:34 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_HPP
#define EXTRA_HPP

namespace ft
{
	template<typename T>
	struct remove_cv {
    	typedef T type;
	};

	template<typename T>
	struct remove_cv<const T> {
    	typedef T type;
	};
			/*+volatile*/
	template<typename T>
	struct remove_volatile {
    	typedef T type;
	};

	template<typename T>
	struct remove_volatile<volatile T> {
    	typedef T type;
	};

		/*swap*/
	template <typename T>
	void swap(T& x, T&y)
	{
		T tmp(x);
		x = y;
		y = tmp;
	}
		/*is_same*/
	template<typename T, typename U>
	struct is_same {
    	static const bool value = false;
	};

	template<typename T>
	struct is_same<T, T> {
		static const bool value = true;
	};
		/*is charchater*/
	template <class T>
	struct is_char{
		static const bool value = false;
	};
	template <>
	struct is_char<char>{
		static const bool value = true;
	};
	template <>
	struct is_char<unsigned char>{
		static const bool value = true;
	};
} // namespace ft



#endif