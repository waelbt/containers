/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:47:27 by waboutzo          #+#    #+#             */
/*   Updated: 2023/01/26 00:01:10 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template <typename T>
class Node 
{
	public:
		const T _key;
		Node *_left;
		Node *_right;

		Node() : _key(), _left(), _right(){}
		Node(T key) : _key(key), _left(), _right(){}
		Node(const Node& obj) : _key(obj._key){
			*this = obj;}
		Node& operator=(const Node& obj){
			_left = obj._left;
			_right = obj._right;
			return *this;
		}
};

template <typename T>
class tree
{
	public:
		typedef  T 					value_type;
		typedef  Node<value_type>	node_type;
		typedef  Node<value_type>*	pointer;
		typedef  Node<value_type>&	reffrence;
	private :
		pointer	root;
		pointer		insert(pointer node, int key)
		{
			if (!node)
				node = new node_type(key);
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
	public:
		tree() : root(NULL){};
		void insert(value_type key){
			root = insert(root, key);
		}
		void inorder(){
			inorder_print(root, 0);
		}
};

#endif