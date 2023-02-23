/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:51:08 by waboutzo          #+#    #+#             */
/*   Updated: 2023/02/23 18:58:57 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "vector/vector.hpp"
#include "map/map.hpp"
#include "set/set.hpp"
#include "stack/stack.hpp"

#include <vector>
#include <map>
#include <set>
#include <stack>

#define RESULTAT(y, x) ((x) ? (std::cout << y << " \033[1;32mAC\033[0m\n") : (std::cout << y << " \033[1;31mWA\033[0m\n"))
#define MAX_VAL 750
#endif