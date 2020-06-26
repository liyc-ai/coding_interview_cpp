#pragma once
/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/
#include "headers.h"

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL) return NULL;
        // get pRoot
        TreeLinkNode* pRoot = pNode;
        while (pRoot->next != NULL)
        {
            pRoot = pRoot->next;
        }
        // in-order walk, by stack;
        stack<TreeLinkNode*> sk;
        TreeLinkNode* next = pRoot;
        bool flag = false;
        while (next || !sk.empty())
        {
            while (next)
            {
                sk.push(next);
                next = next->left;
            }
            next = sk.top();
            sk.pop();
            if (flag) return next;
            if (next == pNode)
            {
                flag = true;
            }
            next = next->right;
        }
    }
};