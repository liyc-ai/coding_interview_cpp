#pragma once
/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，
第三行按照从左到右的顺序打印，其他行以此类推。
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        // breadth-first search
        queue<TreeNode*> bf;
        bf.push(pRoot);
        vector<vector<int>> ans;
        if (pRoot == NULL) return ans;
        int flag = 0;
        while (!bf.empty())
        {
            int sz = bf.size();
            vector<int> layer;
            while (sz--)
            {
                TreeNode* rhd = bf.front();
                bf.pop();
                layer.push_back(rhd->val);
                if (rhd->left) bf.push(rhd->left);
                if (rhd->right) bf.push(rhd->right);
            }
            if(flag & 1)
            {
                reverse(layer.begin(), layer.end());
            } 
            ans.push_back(layer);
            ++flag;
        }
        return ans;
    }

};