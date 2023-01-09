/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:51:49 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/09 16:32:43 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TOOLS_HPP
# define	TOOLS_HPP

namespace ft
{

	template <class T>
	void swap ( T& a, T& b ){
  		T c(a);
		a = b;
		b = c;
	}
	
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
}

#endif