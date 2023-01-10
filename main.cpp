/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/09 23:37:16 by waboutzo         ###   ########.fr       */
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

	

// int main(void)
// {
// 	ft::vector<int> vec(4, 5);
// 	std::cout << vec.size() << " " << vec.capacity() << std::endl;
// 	vec.push_back(9);
// 	std::cout << vec.size() << " " << vec.capacity() << std::endl;
// 	 std::cout << *(vec.end() - 1) << std::endl;
// 	// std::cout << vec.size() << " " << vec.capacity() << std::endl;
// 	// vec.assign(0,4);
// 	// std::cout << vec.size() << " " << vec.capacity() << std::endl;

// 	// vec.assign(10,4);
// 	// std::cout << vec.size() << " " << vec.capacity() << std::endl;
//     //     v.assign(0, 'c');

//     //     //CHECK_AND_PRINT_ALL(v);

//     //     v.assign(64, 'A');

// 	// std::vector<int> b(a.begin(), a.end());
// 	// for (std::vector<int>::iterator it = b.begin(); it < b.end(); it++)
// 	//	std::cout << a.end() - a.begin() << std::endl;
// 		// std::vector<unsigned char> ab;
// 	// std::cout << a.get_allocator() << std::endl;
//     // // ft::vector<int> b;
// 	// // a = b;
//     // srand(time(NULL));
// 	// for (int i = 0; i < 10; i++)
// 	// {
//     // 	// const int value = rand();
//     // 	a.push_back(i);
//     // 	// b.push_back(value);
// 	// }
// 	// for(size_t i = 0; i < a.size(); i++)
// 	// 	std::cout << a[i] << std::endl;
// 	// // ft::swap(a, b);
//   	return 0;
// }

int main(void)
{
	ft::vector<double> vec;
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	vec.clear();
	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	// for (int i = 0; i < 26; ++i) {
    // 	vec.push_back(45.0123);
	// 	std::cout << vec.size() << " " << vec.capacity() << std::endl;
	// 	std::cout << *(vec.end() - 1) << " " << *(vec.begin()) << std::endl;
    //         // CHECK_AND_PRINT_ALL(v);
	// }
	return 0;
}