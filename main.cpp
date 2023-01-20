/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/20 23:39:13 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector/vector.hpp"
#include  "stack/stack.hpp"
#include <vector>
#include <utility>
#include "utility/pair.hpp"

int main () {
	{
  		ft::pair <int,int> foo;
  		ft::pair <int,int> bar;
	
  		foo = ft::make_pair (10,20);
  		bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
	
  		std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  		std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	}
	{
		ft::pair <int,int> foo(10,20);
		ft::pair <double,char> bar(10.5,'A');

		std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  		std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
	}
  return 0;
}