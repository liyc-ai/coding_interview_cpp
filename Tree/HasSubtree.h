#pragma once
/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

子结构：结构相同，相应节点的值相等。
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
	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL) return true;
		if (pRoot1 == NULL) return false;
		if (pRoot1->val == pRoot2->val)
		{
			return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
		}
		return false;
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL) return false;
		bool result = false;
		if (pRoot1->val == pRoot2->val)
		{
			result = isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
		}
		if (!result)
		{
			result = isSubtree(pRoot1->left, pRoot2);
		}
		if (!result)
		{
			result = isSubtree(pRoot1->right, pRoot2);
		}
		return result;
	}
};
