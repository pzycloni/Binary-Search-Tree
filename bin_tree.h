#pragma once

template <class Tkey> class TreeNode {
	TreeNode* left;
	TreeNode* right;
	Tkey value;

	public:
		TreeNode(Tkey);
		~TreeNode();
		friend class SearchTree<Tkey>;
		friend class BraidedSearchTree<Tkey>;
};

template <class Tkey> TreeNode<Tkey>::TreeNode(Tkey info) : left(0), right(0), value(info) {}
template <class Tkey> TreeNode<Tkey>::~TreeNode(){
	if (left) delete left;
	if (right) delete right;
}

template <class Tkey> class SearchTree {
	private:
		TreeNode* root;
		int(*)(Tkey, Tkey) cmp;
		TreeNode<Tkey>* _findMin(TreeNode<Tkey>*);
		TreeNode<Tkey>*	_finMax(TreeNode<Tkey>*);
		void _remove(Tkey, TreeNode<Tkey>*);
		void _inorder(TreeNode<Tkey>*, void(*)(Tkey));
	public:
		SearchTree(int(*)(Tkey, Tkey));
		~SearchTree();
		int isEmpty();
		Tkey findMin();
		Tkey findMax();
		Tkey find(Tkey);
		void inorder (void(*) (T) );
  		void insert(Tkey);
 		void remove(Tkey);
  		Tkey removeMin();
};

template <class Tkey> SearchTree<Tkey>::SearchTree(int(*info)(Tkey, Tkey)) : root(0), cmp(info){}

template <class Tkey> SearchTree<Tkey>::isEmpty(){
	return (root == NULL);
}

template <class Tkey> SearchTree<Tkey>::~SearchTree(){
	if (root) delete root;
}
template <class Tkey> SearchTree<Tkey>::find(Tkey info){
	SearchTree* n = root;
	while (n){
		int temp = (*cmp)(info, n->value);
		if (temp < 0) n = n->left;
		else if (temp > 0) n = n->right;
		else return n->value;
	}
}