/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/16 19:42:44 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include <sstream>
      
int main ()
{

  // {
  //   ft::vector<int> myvector (3,100);
  //   ft::vector<int>::iterator it;
  
  //   it = myvector.begin();
  //   it = myvector.insert ( it , 200 );
    
  //   myvector.insert (it,2,300);
  
  //   // "it" no longer valid, get a new one:
  //   it = myvector.begin();
  //   std::cout << "before:";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  
  //   std::vector<int> anothervector (2,99);
  //   myvector.insert (it+2,anothervector.begin(),anothervector.end());
    
  //   // int myarray [] = { 501,502,503 };
  //   // myvector.insert (myvector.begin(), myarray, myarray+3);
  
  //   std::cout << "ft myvector contains:";
  //   for (it=myvector.begin(); it<myvector.end(); it++)
  //     std::cout << ' ' << *it;
  //   std::cout << '\n';
  // }

  //  {
  //       // This test checks if vector works with iterators tagged as std::input_iterator_tag
  //       std::istringstream str("1 2 3 4 5 6 7 8 9 0 A B C D E F");
  //       std::istreambuf_iterator<char> it(str), end;
  //       // for (std::istreambuf_iterator<char> it(str); it != end;)
  //       //   std::cout << ' ' << *(it++);
  //   		// std::cout << '\n';
  //       ft::vector<char> v(2, 'U');
  //       v.insert(v.end(), it, end);
  //       // for (ft::vector<char>::iterator it = v.begin(); it != v.end(); it++)
  //       //   std::cout << ' ' << *it;
  //   		// std::cout << '\n';
        
	// 		}  
  {
    ft::vector<int> a(5, 5);
    ft::vector<int> b(a.begin(), a.end());
  }
  return 0;
}