/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:55:40 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/06 22:02:09 by waboutzo         ###   ########.fr       */
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

int main (void)
{
  ft::vector<int> vec(10, 100);
  std::cout << vec.size() << " " << vec.capacity() << std::endl;
  vec.assign(7, 13);
  std::cout << vec.size() << " " << vec.capacity() << std::endl;
  return 0;
}