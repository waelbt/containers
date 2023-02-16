/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/16 16:07:20 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector/vector.hpp"
# include <vector>
# include <map>
# include "map/tree.hpp"
# include "map/tree_iterator.hpp"
# include "map/map.hpp"
# include <iostream>
# include <algorithm>

#include "fancy_tree.hpp"

int main(void)
{
	TREE<int, std::less<int> >  a;

	a.search(5);
	// fancy_tree<int> tree;
	// std::map<int, int> mymap;
	// std::cout << mymap.max_size() << std::endl;
	// TREE<int>::iterator it;
	// mymap.insert(std::make_pair(5, 4));
	// mymap.insert(std::make_pair(5, 4));
	// mymap.insert(std::make_pair(5, 4));
	// mymap.insert(std::make_pair(5, 4));
	// mymap.insert(std::make_pair(5, 4));
	// mymap.insert(std::make_pair(5, 4)23);
	// mymap.insert(std::make_pair(5, 4));
	// mymap.insert(std::make_pair(5, 4));
	// tree.print_tree(mymap._tree.getROOT(), V_VIEW);
	return 0;
}