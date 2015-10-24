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
		void _remove(const NODE&, TreeNode<NODE>*);

	public:
		Tree() : root(0){};
		~Tree() {
			removeTree(root);
		}
		void insert(const NODE &);
		/*TODO: доделать удаление дерева*/
		void removeTree(TreeNode<NODE>*&); 
		int cmp(const NODE &node, const NODE &key){
			if (node > key)
				return -1;
			else if (node < key)
				return 1;
			else return 0;
		}
		void remove(const NODE &);
		NODE findMin(){
			TreeNode<NODE> *node = _findMin(root);
			return (node ? node->value : NULL);
		}
		NODE findMax(){
			TreeNode<NODE> *node = _findMax(root);
			return (node ? node->value : NULL);
		}
		void removeMin(){
			int found = findMin();
			if (found)
				cout << "min element " << found << " was delete!\n";
			else
				cout << "min element not found!\n";
		}
		void removeMax(){
			int found = findMax();
			if (found)
				cout << "min element " << found << " was delete!\n";
			else
				cout << "min element not found!\n"
		}
};


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
void Tree<NODE>::_removeTree(TreeNode<NODE> *&node){
	if (node == NULL) return;
	removeTree(node->left);
	removeTree(node->right);
	printf("Deleted node ( %d )", node->value);
	delete node;
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