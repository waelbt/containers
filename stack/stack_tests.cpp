/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:00:46 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/22 11:39:28 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include <deque>
#include <vector>
#include <stack>
#define NAMESPACE std
#define RESULTAT(y, x) ((x) ? (std::cout << y << " \033[1;32mAC\033[0m\n") : (std::cout << y << " \033[1;31mWA\033[0m\n"))

int main(void)
{
	std::cout << "\t\t\033[1;32mSTACK\033[0m" << std::endl;

	{
		NAMESPACE::vector<int> myvector (2,200);
		NAMESPACE::stack<int,NAMESPACE::vector<int> > s(myvector);
		NAMESPACE::stack<int> mystack;
		int sum (0);

		RESULTAT("constructor :", s.size() == myvector.size());
		for (int i=1;i<=10;i++) mystack.push(i);
		RESULTAT("size :",mystack.size() == 10);
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		RESULTAT("empty :", sum == 55);
		RESULTAT("top :", sum == 55);
		RESULTAT("pop :", sum == 55);
	}

	return 0;
}