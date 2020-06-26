#pragma once
/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
#include "headers.h"


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* helper(vector<int>& pre, vector<int>& vin, int start, int low, int high)
    {
        cout << start << ' ' << low << ' ' << high<< endl;
        TreeNode* root = new TreeNode(pre[start]), * left = NULL, * right = NULL;
        int index = find(vin.begin() + low, vin.begin() + high, pre[start]) - vin.begin();
        if (index != low)
        {
            left = helper(pre, vin, start + 1, low, index); 
        }
        root->left = left;
        if (index != high-1)
        {
            start = start + index - low + 1;
            right = helper(pre, vin, start, index + 1, high);
        }
        root->right = right;
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        // recursive
        return helper(pre, vin, 0, 0, pre.size());  // start for pre; low, high for vin
    }
};
