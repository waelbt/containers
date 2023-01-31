/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:47:27 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/31 07:21:55 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <deque>

// namespace ft
// {
	template <typename T>
	class Node 
	{
		public:
			T _value;
			Node *_left;
			Node *_right;
	
			Node(T key) : _value(key), _left(), _right(){}
			Node(const Node& obj) : _value(obj._value){
				*this = obj;}
			Node& operator=(const Node& obj){
				_left = obj._left;
				_right = obj._right;
				return *this;
			}
			~Node(){}
	};

	template <typename T, class Alloc = std::allocator<T> >
	class BST
	{
		public:
			typedef		T 					value_type;
			typedef 	Alloc               allocator_type;
			typedef 	typename allocator_type::template rebind<Node<T> >::other	node_allocater;
			typedef		Node<value_type>	node_type;
			typedef		Node<value_type>*	pointer;
			typedef		Node<value_type>&	reffrence;
			
		private :
			pointer	root;
			node_allocater _alloc_node;

			pointer		insert(pointer node, T key)
			{
				if (!node)
				{
					node = _alloc_node.allocate(1);
					_alloc_node.construct(node, key);
				}
				else if (key <= node->_value)
					node->_left = insert(node->_left, key);
				else if (key > node->_value)
					node->_right = insert(node->_right, key);
				return node;
			}
			void		inorder_print(pointer root, int level = 0){
				if (!root)
					return;
	   			inorder_print(root->_left, level + 3);
	    		std::cout << std::string(level, ' ') << root->_value << "\n";
	    		inorder_print(root->_right, level + 3);
			}
			void breadthFirstTraversal(pointer root){
				std::deque<std::pair<pointer, int> > queue;
				int level = 0;
				queue.push_back(std::make_pair(root, level));
				int last_level = -1;
				while (!queue.empty())
				{
					std::pair<pointer, int> current = queue.front();
					queue.pop_front();
					if (last_level == current.second)
						std::cout << " ";
					else
						std::cout << std::endl;
					std::cout << current.first->_value;
					last_level = current.second;
					if (current.first->_left)
						queue.push_back(std::make_pair(current.first->_left, level + 1));
					if (current.first->_right)
					{
						queue.push_back(std::make_pair(current.first->_right, level + 1));
						level++;
					}
				}
			}
		public:
			BST() : root() {}
			void insert(T key){
				root = insert(root, key);
			}
			void inorder(){
				inorder_print(root, 0);
			}
			void breadthFirstTraversal(){
				breadthFirstTraversal(root);}
			~BST(){
				// tan7yd leaks
			};
	};				
#endif


// void	insert_fixedup(pointer& new_node)
// 			{
// 				pointer uncle;

// 				while (new_node->_parent && !new_node->_parent->_black)
// 				{
// 					if (!new_node->_parent->_parent)
// 						break;
// 					if (new_node->_parent == new_node->_parent->_parent->_left)
// 					{
// 						uncle = new_node->_parent->_parent->_right;
// 						if (!uncle)
// 							break;
// 						if (!uncle->_black)
// 						{
// 							// recolor
// 							new_node->_parent->_black = true;
// 							uncle->_black = true;
// 							new_node->_parent->_parent->_black = false;
// 							new_node = new_node->_parent->_parent;
// 						}
// 						else
// 						{
// 							if (new_node == new_node->_parent->_right)
// 							{
// 								new_node = new_node->_parent;
// 								left_rotate(new_node);
// 								new_node->_parent->_black = true;
// 								new_node->_parent->_parent->_black = true;
// 								right_rotate(new_node->_parent->_parent);
// 							}
// 						}
// 					}
// 					else
// 					{
// 						uncle = new_node->_parent->_parent->_left;
// 						if (!uncle)
// 							break;
// 						if (!uncle->_black)
// 						{
// 							// recolor
// 							new_node->_parent->_black = true;
// 							uncle->_black = true;
// 							new_node->_parent->_parent->_black = false;
// 							new_node = new_node->_parent->_parent;
// 						}
// 						else
// 						{
// 							if (new_node == new_node->_parent->_right)
// 							{
// 								new_node = new_node->_parent;
// 								left_rotate(new_node);
// 								new_node->_parent->_black = true;
// 								new_node->_parent->_parent->_black = true;
// 								right_rotate(new_node->_parent->_parent);
// 							}
// 						}
// 					}
// 				}
// 			}