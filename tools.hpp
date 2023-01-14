/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:51:49 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/14 04:44:03 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TOOLS_HPP
# define	TOOLS_HPP

namespace ft
{

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
	struct is_integral{
		static const bool value = false;
	};
	
	template <>
	struct is_integral<bool>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<char>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<char16_t>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<char32_t>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<wchar_t>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<signed char>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<short int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<long int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<long long int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<unsigned char>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<unsigned short int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<unsigned int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<unsigned long int>{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<unsigned long long int>{
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
			/*remove const*/
	template<typename T>
	struct remove_cv {
    	typedef T type;
	};

	template<typename T>
	struct remove_cv<const T> {
    	typedef T type;
	};
} // namespace ft

#endif