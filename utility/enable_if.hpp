/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:24:23 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/21 11:25:27 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP


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
} // namespace ft


#endif
