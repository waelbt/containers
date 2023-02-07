/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/07 12:57:27 by waboutzo         ###   ########.fr       */
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

// RB-INSERT(T, k)
//     
//      while k.parent.color == RED
//          if k.parent == k.parent.parent.right
//             u = k.parent.parent.left //uncle
//              if u.color == RED // case 3.1
//                 u.color = BLACK
//                 k.parent.color = BLACK
//                 k.parent.parent.color = RED
//                 k = k.parent.parent
//              else if k == k.parent.left // case 3.3.1 and 3.3.2
//                     k = k.parent
//                     LEFT-ROTATE(T, k)
//                 k.parent.color = BLACK
//                 k.parent.parent.color = RED
//                 RIGHT-ROTATE(T, k.parent.parent)
//         else (same as then clause with “left” and “right” exchanged)
//      T.root.color = BLACK

// while (new_node->_parent && !new_node->_parent->_black)
// {
// 	if (new_node->_parent == new_node->_parent->_parent->_right)
// 	{
// 		std::cout << "www" << std::endl;
// uncle = new_node->_parent->_parent->_left;
// if (!uncle->_black)
// {
// 	uncle->_black = true;
// 	new_node->_parent->_black = true;
// 	new_node->_parent->_parent->_black = true;
// 	new_node = new_node->_parent->_parent;
// }
// else if (new_node == new_node->_parent->_left)
// {
// 	new_node = new_node->_parent;
// 	left_rotate(new_node);
// 	new_node->_parent->_black = true;
// 	new_node->_parent->_parent->_black = false;
// 	right_rotate(new_node->_parent->_parent);
// }
	// }

	// else
	// {
	// 	std::cout << "www" << std::endl;
		// uncle = new_node->_parent->_parent->_right;
		// if (!uncle->_black)
		// {
		// 	uncle->_black = true;
		// 	new_node->_parent->_black = true;
		// 	new_node->_parent->_parent->_black = true;
		// 	new_node = new_node->_parent->_parent;
		// }
		// else if (new_node == new_node->_parent->_right)
		// {
		// 	new_node = new_node->_parent;
		// 	left_rotate(new_node);
		// 	new_node->_parent->_black = true;
		// 	new_node->_parent->_parent->_black = false;
		// 	right_rotate(new_node->_parent->_parent);
		// }
// 	}
// }

int main(void)
{
    // const ft::vector<int> a;
    // ft::vector<int>::iterator =  a.begin();
    RBT<int> a;
    a.insert(5);
    a.insert(10);
    a.insert(8);
	a.insert(2);
	a.insert(12);
	a.insert(6);
	a.insert(9);
    // a.insert(3);
    // a.insert(0);
	fancy_tree<int> tree;
	tree.print_tree(a._root, V_VIEW);
	// a.left_rotate(a._root);
	// a.right_rotate(a._root);
	// std::cout << "\n*********" << std::endl;
	//  a.breadthFirstTraversal();
    // a.left_rotate(NULL);
    // a.breadthFirstTraversal();
    return 0;
}