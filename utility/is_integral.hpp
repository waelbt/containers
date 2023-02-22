/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:27:06 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 10:40:27 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP


#include "extra.hpp"

namespace ft
{
	template <typename T>
	struct is_integral_traits{
		static const bool value = false;
	};
	
	template <>
	struct is_integral_traits<bool>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<char>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<char16_t>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<char32_t>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<wchar_t>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<signed char>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<short int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<long int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<long long int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<unsigned char>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<unsigned short int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<unsigned int>{
		static const bool value = true;
	};
	
	
	template <>
	struct is_integral_traits<unsigned long int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral_traits<unsigned long long int>{
		static const bool value = true;
	};

	template <typename T>
	struct is_integral{
		static const bool value = is_integral_traits<typename ft::remove_cv<typename ft::remove_volatile<T>::type>::type>::value;
	};
} // namespace ft

#endif