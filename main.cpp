/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/06 17:58:02 by waboutzo         ###   ########.fr       */
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

int main ()
{
  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  std::cout << "size: " << myvector.size() << "\n";
  std::cout << "capacity: " << myvector.capacity() << "\n";
  std::cout << "max_size: " << myvector.max_size() << "\n";
  std::cout << "max_size: " << SIZE_MAX / sizeof(int) << "\n";
  return 0;
}

// int main()
// {
//         // ft::vector<int> vec(20, 10);
//         // std::cout << *(vec.begin()) << std::endl;
//     //     std::cout << "size :"<< vec.size() << std::endl;
//     //     std::cout << "capacity :" << vec.capacity() << std::endl;
        
//     //     ft::vector<int> vec1(100, 1);
//     //     std::cout << std::endl;
//     //     std::cout << "size :"<< vec1.size() << std::endl;
//     //     std::cout << "capacity :" << vec1.capacity() << std::endl;

//     //     vec = vec1;
//     //     std::cout << std::endl;
//     //     std::cout << "size :"<< vec.size() << std::endl;
//     //     std::cout << "capacity :" << vec.capacity() << std::endl;
//     // }
//     //     std::cout << "\t**************************\t" << std::endl;
//     {
//         std::vector<int> vec(20, 10);
//         std::cout << "size :"<< vec.size() << std::endl;
//         std::cout << "capacity :" << vec.capacity() << std::endl;

//         std::vector<int> vec1(20, 1);
//         vec1.push_back(5);
//         std::cout << std::endl;
//         std::cout << "size :"<< vec1.size() << std::endl;
//         std::cout << "capacity :" << vec1.capacity() << std::endl;

//         vec = vec1;
//         std::cout << std::endl;
//         std::cout << "size :"<< vec.size() << std::endl;
//         std::cout << "capacity :" << vec.capacity() << std::endl;
//     }
//     return 0;
// }