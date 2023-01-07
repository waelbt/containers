/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/07 20:48:37 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <memory>
# include "vector.hpp"
# include <vector>


// int main(void)
// {
// 	// ft::vector<int> a;
// 	std::vector<int> vec {1, 2, 3};
// 	std::cout << sizeof(vec) << std::endl;
// 	std::cout << vec.size() << " " << a.capacity() << std::endl;
// 	return 0;	
// }

// int main (void)
// {
//   ft::vector<int> vec(10, 100);
//   ft::vector<int> vec1(300, 100);
//   std::cout << vec.size() << " " << vec.capacity() << std::endl;
//   std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
//   vec.swap(vec1);
//   std::cout << vec.size() << " " << vec.capacity() << std::endl;
//   std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
//   return 0;
// }

int main(void)
{
    std::vector<int> a;
    ft::vector<int> b;

    srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
    	const int value = rand();
    	a.push_back(value);
    	b.push_back(value);
	}
    std::cout << a.size() << " " << a.capacity() << std::endl;
   	std::cout << b.size() << " " << b.capacity() << std::endl;
	a.resize(100, 3);
	b.resize(100, 3);
	std::cout << a.size() << " " << a.capacity() << " " << a.back() << " " << a.front() << std::endl;
   	std::cout << b.size() << " " << b.capacity()  << " " << b.back() << " " << b.front() << std::endl;
  	return 0;
}