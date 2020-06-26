#pragma once
/*
请实现两个函数，分别用来序列化和反序列化二叉树

二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），
以,表示一个结点值的结束（value,）。

二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
例如，我们可以把一个只有根节点为1的二叉树序列化为"1,"，然后通过自己的函数来解析回这个二叉树
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
    // preorder
    char* Serialize(TreeNode* root) {
        string ans;
        stack<TreeNode* > chs;
        chs.push(root);
        while (!chs.empty())
        {
            TreeNode* cur = chs.top();
            chs.pop();
            if (!cur) ans += "#";
            else
            {
                ans += to_string(cur->val);
                chs.push(cur->right);
                chs.push(cur->left);
            }
            ans += "!";
        }
        // convert string to char*
        int len = ans.length();
        char* charAns = new char[len + 1];
        for (int i = 0; i < len; ++i)
        {
            charAns[i] = ans[i];
        }
        charAns[len] = '\0';
        return charAns;
    }
    TreeNode* Deserialize(char* str) {
        string newStr(str);
        if (newStr.size() == 0) return NULL;
        queue<TreeNode*> nodes; // get all the nodes
        for (int i = 0; i < newStr.length(); ++i)
        {
            TreeNode* newNode;
            if (newStr[i] != '!')
            {
                if (newStr[i] != '#')
                {
                    int num = 0;
                    while (newStr[i] >= '0' && newStr[i] <= '9')
                    {
                        num = num * 10 + (newStr[i++] - '0');
                    }
                    newNode = new TreeNode(num);
                }
                else newNode = NULL;
                nodes.push(newNode);
            }
        }
        
        TreeNode* pRoot = nodes.front();
        nodes.pop();

        TreeNode* head = pRoot;
        stack<TreeNode*> sk;
        while (!nodes.empty())
        {
            while (head)
            {
                if (!sk.empty() && !(sk.top()->left))
                {
                    sk.top()->left = head;
                }
                sk.push(head);
                head = nodes.front();
                nodes.pop();
            }
            TreeNode* tmp = nodes.front();
            nodes.pop();
            if (tmp)
            {
                head = tmp;
                sk.top()->right = head;
            }
            sk.pop();
        }
        return pRoot;
    }
};