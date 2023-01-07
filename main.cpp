/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/07 17:53:50 by waboutzo         ###   ########.fr       */
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
  {
    std::vector<int> vec(19, 100);
    std::cout << "size  :"<< vec.size() << " capacity: " << vec.capacity() << std::endl;
    vec.push_back(6);
    std::cout << "size  :"<< vec.size() << " capacity: " << vec.capacity() << std::endl;
    vec.pop_back();
    std::cout << "size  :"<< vec.size() << " capacity: " << vec.capacity() << std::endl;
    std::cout << vec.back() << std::endl;
  }
  {
    std::vector<int> vec(19, 100);
    std::cout << "size  :"<< vec.size() << " capacity: " << vec.capacity() << std::endl;
    vec.push_back(6);
    std::cout << "size  :"<< vec.size() << " capacity: " << vec.capacity() << std::endl;
    vec.pop_back();
    std::cout << "size  :"<< vec.size() << " capacity: " << vec.capacity() << std::endl;
    std::cout << vec.back() << std::endl;
  }
  return 0;
}