#ifndef _TREE_H
#define _TREE_H

template <class NODE> class Tree;
#include "node_tree_bynary_class.h"

template <class NODE>
class Tree {
	private:
		TreeNode<NODE> *root;

		inline TreeNode<NODE>* _getRoot(){ return root; }
		TreeNode<NODE>* _findMax(TreeNode<NODE>*);
		TreeNode<NODE>* _findMin(TreeNode<NODE>*);
		TreeNode<NODE>* _find(const NODE &, TreeNode<NODE>*);
		void _remove(const NODE &, TreeNode<NODE>*);
		void _removeTree(TreeNode<NODE>*);

	public:
		Tree() : root(0){};
		~Tree() { }
		void insert(const NODE &);
		int cmp(const NODE &, const NODE &);
		void remove(const NODE &);
		NODE find(const NODE &);
		NODE findMin();
		NODE findMax();
		void removeMin();
		void removeMax();
		bool isEmpty();
};

template <class NODE>
int Tree<NODE>::cmp(const NODE &node, const NODE &key){
	if (node > key)
		return -1;
	else if (node < key)
		return 1;
	else return 0;
}
template <class NODE>
bool Tree<NODE>::isEmpty(){
	return !root;
}

template <class NODE>
void Tree<NODE>::removeMin(){
	TreeNode<NODE> *found = _findMin(root);
	if (found) {
		int element = found->value;
		_remove(found->value, found);
		printf("Min element ( %d ) was delete!\n", element);
	}
	else printf("Min element not found!\n");
}

template <class NODE>
void Tree<NODE>::removeMax(){
	TreeNode<NODE>* found = _findMax(root);
	if (found){
		int element = found->value;
		_remove(found->value, value);
		printf("Max element ( %d ) was delete!\n", element);
	}
	else printf("Max element not found!\n");
}

template <class NODE>
NODE Tree<NODE>::find(const NODE &val){
	TreeNode<NODE> *node = _find(val, root);
	return (node ? node->value : NULL);
}

template <class NODE>
NODE Tree<NODE>::findMin(){
	TreeNode<NODE> *node = _findMin(root);
	return (node ? node->value : NULL);
}

template <class NODE>
NODE Tree<NODE>::findMax(){
	TreeNode<NODE> *node = _findMax(root);
	return (node ? node->value : NULL);
}

template <class NODE>
void Tree<NODE>::insert(const NODE &val){
	if (root == NULL){
		root = new TreeNode<NODE>(val);
		return;
	}
	else {
		TreeNode<NODE> *pointer = NULL, *node = root;
		int result;
		while (node) {
			pointer = node;
			result = cmp(node->value, val);
			if (result < 0)
				node = pointer->left;
			else if (result > 0)
				node = pointer->right;
			else return;
		}
		if (result < 0)
			pointer->left = new TreeNode<NODE>(val);
		else
			pointer->right = new TreeNode<NODE>(val);
	}
}

template <class NODE>
void Tree<NODE>::remove(const NODE &val){
	_remove(val, root);
}

template <class NODE>
void Tree<NODE>::_remove(const NODE &val, TreeNode<NODE> *node){
	if (node == NULL)
		return;
	int result = cmp(node->value, val);
	if (result < 0)
		_remove(val, node->left);
	else if (result > 0)
		_remove(val, node->right);
	else {
		if (node->left == NULL){
			TreeNode<NODE> *old = node;
			node = old->right;
			delete old;
		}
		else if (node->right == NULL){
			TreeNode<NODE> *old = node;
			node = old->left;
			delete old;
		}
		else {
			TreeNode<NODE> *min = _findMin(node->right);
			node->value = min->value;
			_remove(min->value, node->right);
		}
	}
}

template <class NODE>
TreeNode<NODE>* Tree<NODE>::_find(const NODE &val, TreeNode<NODE> *node){
	if (node == NULL) return NULL;
	int result = cmp(node->val, val);
	if (result < 0)
		node = node->left;
	else if (result > 0)
		node = node->right;
	else return node;
}

template <class NODE>
TreeNode<NODE>* Tree<NODE>::_findMin(TreeNode<NODE>* node){
	if (node == NULL) return NULL;
	while (node->left) {
		node = node->left;
	}
	return node;
}

template <class NODE>
TreeNode<NODE>* Tree<NODE>::_findMax(TreeNode<NODE>* node){
	if (node == NULL) return NULL;
	while (node->right) {
		node = node->right;
	}
	return node;
}

#endif;