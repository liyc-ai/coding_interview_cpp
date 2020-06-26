#pragma once
/*
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。
*/
#include "headers.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	int getHeight(TreeNode* pRoot)
	{
		if (!pRoot) return 0;
		int leftHeight = getHeight(pRoot->left);
		int rightHeight = getHeight(pRoot->right);
		return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
	}
	int TreeDepth(TreeNode* pRoot)
	{
		// recursive
		return getHeight(pRoot);
	}
};
