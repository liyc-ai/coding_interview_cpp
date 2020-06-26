#pragma once
/*
输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
	class Node
	{
	public:
		int val;
		int color;
		Node* left;
		Node* right;
		Node(int x): 
			val(x), left(NULL),right(NULL),color(0){}
	};
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ans;
		if (root == NULL) return ans;
		// clone tree
		Node* pRoot, *node;
		pRoot = node = new Node(root->val);
		queue<Node*> tree;
		queue<TreeNode*> original;
		tree.push(node), original.push(root);
		while (!original.empty())
		{
			int sz = original.size();
			while (sz--)
			{
				root = original.front();
				node = tree.front();
				if (root->left)
				{
					Node* left = new Node(root->left->val);
					node->left = left;
					original.push(root->left);
					tree.push(node->left);
				}
				if (root->right)
				{
					Node* right = new Node(root->right->val);
					node->right = right;
					original.push(root->right);
					tree.push(node->right);
				}
				original.pop();
				tree.pop();
			}
		}
		// depth-first search
		int sum = pRoot->val;
		vector<Node*> sk;
		pRoot->color = 1;
		sk.push_back(pRoot);
		while (!sk.empty())
		{
			Node* p = sk.back();
			if (p->left && p->left->color == 0)
			{
				p->left->color = 1;
				sk.push_back(p->left);
				sum += p->left->val;
				continue;
			}
			if (p->right && p->right->color == 0)
			{
				p->right->color = 1;
				sk.push_back(p->right);
				sum += p->right->val;
				continue;
			}
			p->color = 2;
			if (p->left == NULL && p->right == NULL && sum == expectNumber)
			{
				vector<int> path;
				for (int i = 0; i < sk.size(); ++i)
				{
					path.push_back(sk[i]->val);
				}
				ans.push_back(path);
			}
			sum -= p->val;
			sk.pop_back();
		}
		return ans;
	}
};
