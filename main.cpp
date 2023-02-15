/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/15 05:19:40 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector/vector.hpp"
# include <vector>
# include <map>
# include "map/tree.hpp"
# include "map/tree_iterator.hpp"
# include "map/map.hpp"
# include "fancy_tree.hpp"
# include <iostream>
# include <algorithm>

// int main(void)
// {
// 	ft::map<int, int> a;
// 	(void) a;
// 	return 0;
// }


int main ()
{
  ft::map<int,std::string> mymap;
  ft::map<int,std::string>::const_iterator it = mymap.begin();
  // ft::pair<ft::map<int,std::string>::iterator, bool> ins_pair = mymap.insert(ft::make_pair(64, "64str"));
  // std::cout << (*ins_pair.first).first << std::endl;
  // std::cout << (*ins_pair.first).second << std::endl;
  // std::cout << ins_pair.second << std::endl;
  return 0;
}

// int main(void)
// {
// 	fancy_tree<int> tree;
// 	TREE<int> a;
	
// 	TREE<int>::iterator it;
// 	a.insert(15);
// 	a.insert(12);
// 	a.insert(19);
// 	a.insert(18);
// 	a.insert(17);
// 	a.insert(23);
// 	a.insert(8);
// 	a.insert(13);
// 	tree.print_tree(a.getROOT(), V_VIEW);
// 	return 0;
// }