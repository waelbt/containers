/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/13 00:30:30 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector/vector.hpp"
# include <vector>
# include <map>
# include "map/rbt.hpp"
# include "map/map.hpp"
# include "fancy_tree.hpp"


// int main(void)
// {
// 	ft::map<int, int> a;
// 	(void) a;
//     return 0;
// }


#include <iostream>
#include <map>

int main ()
{
  std::map<int,int> mymap;

  std::map<int,int>::key_compare mycomp = mymap.key_comp();

  mymap[4]=100;
  mymap[1]=200;
  mymap[3]=300;

  std::cout << "mymap contains:\n";

  char highest = (mymap.rbegin()++)->first ;   // key value of last element

  std::map<int,int>::iterator it = mymap.begin();
  std::cout << (*it).first << " "<< highest << std::endl;
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  std::cout << '\n';

  return 0;
}





// int main(void)
// {
// 	fancy_tree<int> tree;
//     RBT<int> a;

//     a.insert(15);
//     a.insert(12);
//   	a.insert(19);
// 	a.insert(18);
// 	a.insert(17);
// 	a.insert(23);
// 	a.insert(8);
// 	a.insert(13);
// 	tree.print_tree(a.getROOT(), V_VIEW);
//     // a.deletion(15);
// 	// a.deletion(12);
// 	// a.deletion(19);
// 	// a.deletion(8);
// 	a.deletion(18);
// 	// a.deletion(17);
// 	// a.deletion(13);
// 	a.deletion(23);
// 	tree.print_tree(a.getROOT(), V_VIEW);
//     return 0;
// }