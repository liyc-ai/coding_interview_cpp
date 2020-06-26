#pragma once
/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ans;
		if (!root) return ans;
		deque<TreeNode*> tree;
		tree.push_back(root);
		while (!tree.empty())
		{
			int sz = tree.size();
			while (sz--)
			{
				TreeNode* p = tree.front();
				ans.push_back(p->val);
				if (p->left) tree.push_back(p->left);
				if (p->right) tree.push_back(p->right);
				tree.pop_front();
			}
		}
		return ans;
	}
};
