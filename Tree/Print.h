#pragma once
/*
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
测试用例：
1. {8,6,10,5,7,9,11}

对应输出应该为:

[[8],[6,10],[5,7,9,11]]

2. {5,4,#,3,#,2}

对应输出应该为:

[[5],[4],[3],[2]]

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
            ans.push_back(layer);
        }
        return ans;
    }
};