#pragma once
/*
给定一棵二叉搜索树，请找出其中的第k小的结点。例如(5，3，7，2，4，6，8)中，按结点数值大小顺序第三小结点的值为4。
*/
#include "headers.h"

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    // inorder-walk
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        int cnt = 0;
        vector<TreeNode*> items;
        if (!pRoot) return NULL;
        while (pRoot || !items.empty())
        {
            while (pRoot)
            {
                items.push_back(pRoot);
                pRoot = pRoot->left;
            }
            pRoot = items.back();
            ++cnt;
            items.pop_back();
            if (cnt == k) return pRoot;
            pRoot = pRoot->right;
        }
    }
};
