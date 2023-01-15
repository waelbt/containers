/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:51:49 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/14 23:13:57 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TYPE_TRAITS_HPP
# define	TYPE_TRAITS_HPP

namespace ft
{
				/*remove const*/
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
			/* enable_if */
	template<bool Cond, class T = void>
	struct enable_if {
		
	};
	template<class T>
	struct enable_if<true, T>
	{ 
		typedef T type; 
	};
			/* is integral */

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

	template <typename T>
	struct is_integral{
		static const bool value = is_integral_traits<typename ft::remove_cv<typename ft::remove_volatile<T>::type>::type>::value;
	};
} // namespace ft

#endif