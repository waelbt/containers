/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:51:49 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/19 00:49:53 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TYPE_TRAITS_HPP
# define	TYPE_TRAITS_HPP

namespace ft
{
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

						/*equal*/
	template <class InputIterator1, class InputIterator2>
  	bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
  		while (first1!=last1)
		{
    		if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
      			return false;
 	   		++first1; ++first2;
  		}
  		return true;
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
  		while (first1!=last1)
  		{
    		if (first2==last2 || *first2<*first1) 
				return false;
    		else if (*first1<*first2)
				return true;
    		++first1; ++first2;
  		}
  		return (first2!=last2);
	}
} // namespace ft

#endif