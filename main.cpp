/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/16 00:46:44 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
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

  {
    ft::vector<int> myvector (3,100);
    ft::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert ( it , 200 );
  
    myvector.insert (it,2,300);
  
    // "it" no longer valid, get a new one:
    it = myvector.begin();
  
    std::vector<int> anothervector (2,99);
    myvector.insert (it+2,anothervector.begin(),anothervector.end());
    // int myarray [] = { 501,502,503 };
    // myvector.insert (myvector.begin(), myarray, myarray+3);
  
    std::cout << "std myvector contains:";
    for (it=myvector.begin(); it<myvector.end(); it++)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  return 0;
}