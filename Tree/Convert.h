#pragma once
/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
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
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (!pRootOfTree) return NULL;
		// in-order walk
		stack<TreeNode*> sk;
		TreeNode* head = NULL, * front = NULL;
		while (pRootOfTree || !sk.empty())
		{
			while (pRootOfTree)
			{
				sk.push(pRootOfTree);
				pRootOfTree = pRootOfTree->left;
			}
			pRootOfTree = sk.top();
			sk.pop();
			if (front==NULL)
			{
				head = pRootOfTree;
			}
			else
			{
				front->right = pRootOfTree;
				pRootOfTree->left = front;
			}
			front = pRootOfTree;
			pRootOfTree = pRootOfTree->right;
		}
		return head;
	}
};
