/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:47:27 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/26 19:47:47 by waboutzo         ###   ########.fr       */
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
			T _key;
			Node *_left;
			Node *_right;
	
			Node(T key) : _key(key), _left(), _right(){}
			Node(const Node& obj) : _key(obj._key){
				*this = obj;}
			Node& operator=(const Node& obj){
				_left = obj._left;
				_right = obj._right;
				return *this;
			}
			~Node(){}
	};
	
	template <typename T, class Alloc = std::allocator<Node<T> > >
	class BST
	{
		public:
			typedef		T 										pair;
			typedef Alloc										node_allocater;
			typedef typename node_allocater::template rebind<T>::other	pair_allocater;
			// typedef		Compare				key_compare;
			typedef		Node<pair>	node_type;
			typedef		Node<pair>*	pointer;
			typedef		Node<pair>&	reffrence;
			// key_compare comp;
		private :
			pointer	root;
			node_allocater _alloc_node;
			pair_allocater _alloc_pair;
			pointer		insert(pointer node, T key)
			{
				if (!node)
				{
					node = new node_type(key);
				}
				else if (key <= node->_key)
					node->_left = insert(node->_left, key);
				else if (key > node->_key)
					node->_right = insert(node->_right, key);
				return node;
			}
			void		inorder_print(pointer root, int level = 0){
				if (!root)
					return;
	   			inorder_print(root->_left, level + 3);
	    		std::cout << std::string(level, ' ') << root->_key << "\n";
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
					std::cout << current.first->_key;
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
			void insert(pair key){
				root = insert(root, key);
			}
			void inorder(){
				inorder_print(root, 0);
			}
			void breadthFirstTraversal(){
				breadthFirstTraversal(root);}
			~BST(){};
	};
// }

#endif
