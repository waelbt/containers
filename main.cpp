/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/25 23:53:59 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include <iostream>
// # include "vector/vector.hpp"
// # include  "stack/stack.hpp"
// # include <vector>
# include <map>
// # include <utility>
// # include "utility/pair.hpp"
#include "red-black-tree/bst.hpp"


int main(void)
{
    tree<int> a;

    a.insert(5);
    a.insert(9);
    a.insert(10);
    a.insert(1);
    a.inorder();
    return 0;
}