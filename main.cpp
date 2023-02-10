/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/10 02:10:54 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // # include <iostream>
# include "vector/vector.hpp"
// // # include  "stack/stack.hpp"
# include <vector>
# include <map>
// # include <set>
// // # include <utility>
// // # include "utility/pair.hpp"
#include "red-black-tree/rbt.hpp"
#include "fancy_tree.hpp"

// if (new_node->_parent == new_node->_parent->_parent->_left)
// {
// 	uncle = new_node->_parent->_parent->_right;
// 	if (!uncle)
// 		break;
// 	if (!uncle->_black)
// 	{
// 		// recolor
// 		new_node->_parent->_black = true;
// 		uncle->_black = true;
// 		new_node->_parent->_parent->_black = false;
// 		new_node = new_node->_parent->_parent;
// 	}
// 	else if (new_node == new_node->_parent->_right)
// 	{
// 		new_node = new_node->_parent;
// 		left_rotate(new_node);
// 		new_node->_parent->_black = true;
// 		new_node->_parent->_parent->_black = true;
// 		right_rotate(new_node->_parent->_parent);
// 	}
// }
// else
// {
// 	uncle = new_node->_parent->_parent->_left;
// 	if (!uncle)
// 		break;
// 	if (!uncle->_black)
// 	{
// 		// recolor
// 		new_node->_parent->_black = true;
// 		uncle->_black = true;
// 		new_node->_parent->_parent->_black = false;
// 		new_node = new_node->_parent->_parent;
// 	}
// 	else if (new_node == new_node->_parent->_right)
// 	{
// 		new_node = new_node->_parent;
// 		left_rotate(new_node);
// 		new_node->_parent->_black = true;
// 		new_node->_parent->_parent->_black = true;
// 		right_rotate(new_node->_parent->_parent);
// 	}
// }

int main(void)
{
	fancy_tree<int> tree;
    RBT<int> a;

    a.insert(5);
    a.insert(10);
  	a.insert(8);
	a.insert(2);
	a.insert(12);
	a.insert(6);
	a.insert(9);
    a.insert(3);
	// a.insert(21);
	// a.insert(23);
	// a.insert(0);
	// a.insert(-1);
	tree.print_tree(a.getROOT(), V_VIEW);
    return 0;
}