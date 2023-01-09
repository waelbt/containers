/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:38 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/09 16:31:03 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IS_INTERGRAL_HPP
# define	IS_INTERGRAL_HPP

namespace ft
{
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
}

#endif