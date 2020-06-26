#pragma once
/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。

在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
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
    bool getHeight(TreeNode* pRoot, int* height)
    {
        if (!pRoot)
        {
            *height = 0;
            return true;
        }
        int leftHeight, rightHeight;
        bool leftBalanced = false, rightBalanced = false;
        leftBalanced = getHeight(pRoot->left, &leftHeight);
        rightBalanced = getHeight(pRoot->right, &rightHeight);
        if (leftBalanced && rightBalanced)
        {
            int diff = leftHeight - rightHeight;
            if (diff <= 1 && diff >= -1)
            {
                *height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        // recursive implementation
        int height;
        return getHeight(pRoot, &height);
    }
};
