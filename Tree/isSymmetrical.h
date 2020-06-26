#pragma once
/*
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
测试用例：
1. {8,6,9,5,7,7,5}
结果：false
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        // breadth-first search
        deque<TreeNode*> nodes;
        if (pRoot==NULL) return true;
        nodes.push_back(pRoot);
        while (!nodes.empty())
        {
            int sz = nodes.size();
            for (int i = 0; i < sz / 2; ++i)
            {
                if (!nodes[i] && nodes[sz-1-i] || nodes[i] && !nodes[sz-1-i])
                {
                    return false;
                }
                if (nodes[i] == NULL && nodes[sz - 1 - i] == NULL) continue;
                if (nodes[i]->val != nodes[sz - 1 - i]->val) return false;
            }
            
            while (sz--)
            {
                TreeNode* rhd = nodes.front();
                nodes.pop_front();
                if (rhd != NULL)
                {
                    nodes.push_back(rhd->left);
                    nodes.push_back(rhd->right);
                }
            }
        }
        return true;
    }

};
