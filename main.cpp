/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:50:42 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/23 19:10:42 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.hpp"

void stack_test(void)
{
	std::cout << "\t\t\033[1;32mSTACK\033[0m" << std::endl;

	{
		ft::vector<int> myvector (2,200);
		ft::stack<int,ft::vector<int> > s(myvector);
		ft::stack<int> mystack;
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
}

void vector_test() {
	int tab[7] = {5, 3, 1, 4, 21, 1137};
    ft::vector<int> myvec;
	std::vector<int> vec;
	std::cout << "\t\t\033[1;32mVECTOR\033[0m" << std::endl;
	RESULTAT("default constructor: ", (myvec.size() == vec.size()) &&
		 (myvec.capacity() == vec.capacity() 
		 && (ft::equal(myvec.begin(), myvec.end(), vec.begin()))));
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		myvec.push_back(value);
		vec.push_back(value);
	}
	RESULTAT("push_back: ", (myvec.size() == vec.size()) 
		&& (myvec.capacity() == vec.capacity() 
		&& (ft::equal(myvec.begin(), myvec.end(), vec.begin()))));
	RESULTAT("operator : ", (myvec[0] == vec[0]));
	RESULTAT("at : ", (myvec.at(1) == vec.at(1)));
	RESULTAT("front: ", (myvec.front() == vec.front()));
	RESULTAT("back: ", (myvec.back() == vec.back()));
	while (myvec.size())
		myvec.pop_back(); 
   	RESULTAT("pop_back: ", !(myvec.size()));
	RESULTAT("empty: ", myvec.empty());
	myvec.insert(myvec.begin(), tab, tab + 6);
	RESULTAT("insert: range", myvec.size() == 6 && (myvec.front() == tab[0]) && (myvec.back() == tab[5]));
	ft::vector<int>::iterator it = myvec.insert(myvec.begin(), 4);
    RESULTAT("insert : ", (*it == 4) && myvec.size() == 7 && myvec[0] == 4);
    it = myvec.erase(myvec.begin());
	RESULTAT("erase : ", (*it == 5) && (myvec.size() == 6) && (*(myvec.begin()) == 5));

    myvec.clear();
    RESULTAT("clear : ", (myvec.empty()));
}

void map_test() {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    std::cout << "\t\t\033[1;32mMAP\033[0m" << std::endl;
    RESULTAT("default constructor: ", (std_map.size() == ft_map.size()) &&
             (std_map.empty() == ft_map.empty()));
    std::pair<int, int> pair1(1, 10);
	ft::pair<int, int> ft_pair1(1, 10);
    ft::pair<int, int> ft_pair2(2, 20);
    std::pair<int, int> pair2(2, 20);
    std_map.insert(pair1);
    ft_map.insert(ft_pair1);
    std_map.insert(pair2);
    ft_map.insert(ft_pair2);
	RESULTAT("size: ", ft_map.size() == 2); 
    RESULTAT("insert: ", (std_map.size() == ft_map.size()) && 
            (std_map[1] == ft_map[1]) && (std_map[2] == ft_map[2]));
    std::map<int, int>::iterator std_it = std_map.begin();
    ft::map<int, int>::iterator ft_it = ft_map.begin();
    std_it++;
    ft_it++;
    std_map.erase(std_it);
    ft_map.erase(ft_it);
    RESULTAT("erase: ", (std_map.size() == ft_map.size()) &&
            (std_map[1] == ft_map[1]) && (std_map.count(2) == 0) && (ft_map.count(2) == 0));
    std_map.clear();
    ft_map.clear();
    RESULTAT("clear: ", (std_map.size() == ft_map.size()) && 
            (std_map.empty() == ft_map.empty()));
	RESULTAT("empty: ", ft_map.empty());
}

void set_test() {
    std::set<int> std_set;
    ft::set<int> ft_set;
    std::cout << "\t\t\033[1;32mset\033[0m" << std::endl;
    RESULTAT("default constructor: ", (std_set.size() == ft_set.size()) &&
             (std_set.empty() == ft_set.empty()));
    std_set.insert(5);
    ft_set.insert(10);
    std_set.insert(10);
    ft_set.insert(5);
	RESULTAT("size: ", ft_set.size() == 2); 
    RESULTAT("insert: ", (std_set.size() == ft_set.size()) && ft::equal(std_set.begin(), std_set.end(), ft_set.begin()));
    std::set<int>::iterator std_it = std_set.begin();
    ft::set<int>::iterator ft_it = ft_set.begin();
    std_it++;
    ft_it++;
    std_set.erase(std_it);
    ft_set.erase(ft_it);
    RESULTAT("erase: ", (std_set.size() == ft_set.size()) && ft::equal(std_set.begin(), std_set.end(), ft_set.begin()));
    std_set.clear();
    ft_set.clear();
    RESULTAT("clear: ", (std_set.size() == ft_set.size()) && 
            (std_set.empty() == ft_set.empty()));
	RESULTAT("empty: ", ft_set.empty());
}


int main(void)
{
	vector_test();
	stack_test();
	map_test();
	return 0;
}