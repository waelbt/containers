/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/11 19:47:09 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "vector/vector.hpp"
# include <vector>
# include <map>
# include "red-black-tree/rbt.hpp"
# include "fancy_tree.hpp"


int main(void)
{
	fancy_tree<int> tree;
    RBT<int> a;

    a.insert(15);
    a.insert(12);
  	a.insert(19);
	a.insert(18);
	a.insert(17);
	a.insert(23);
	a.insert(8);
	// a.insert(13);
	tree.print_tree(a.getROOT(), V_VIEW);
    a.deletion(15);
	a.deletion(12);
	tree.print_tree(a.getROOT(), V_VIEW);
    return 0;
}