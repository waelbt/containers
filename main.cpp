/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/08 19:05:04 by waboutzo         ###   ########.fr       */
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
    ft::vector<int> a;
	std::cout << a.get_allocator() << std::endl;
    // // ft::vector<int> b;
	// // a = b;
    // srand(time(NULL));
	// for (int i = 0; i < 10; i++)
	// {
    // 	// const int value = rand();
    // 	a.push_back(i);
    // 	// b.push_back(value);
	// }
	// for(size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << std::endl;
	// // ft::swap(a, b);
  	return 0;
}