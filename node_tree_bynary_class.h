#ifndef _NODE_H
#define _NODE_H

template <class NODE> class TreeNode {
	friend class Tree<NODE>;

	protected:
		TreeNode* left;
		TreeNode* right;
		TreeNode* parent;
		NODE value;

	public:
		TreeNode(const NODE &val) : left(0), right(0), value(val) {};
		NODE get_data();
};

#endif