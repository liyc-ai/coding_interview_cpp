#pragma once
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法。
*/
#include "headers.h"

class Solution {
public:
    struct node
    {
        int val;
        node* next, * pre;
        node(int in_val) :val(in_val), next(NULL), pre(NULL) {};
    };
    Solution() :topNode(NULL), minNode(NULL), buttomNode(NULL) {};
    void push(int value) {
        node* nNode = new node(value);
        if (buttomNode == NULL)
        {
            buttomNode = topNode = minNode = nNode;
        }
        else
        {
            topNode->next = nNode;
            nNode->pre = topNode;
            topNode = nNode;
            if (minNode->val > topNode->val) minNode = topNode;
        }
    }
    void pop() {
        if (minNode == topNode)
        {
            if (topNode->pre != NULL)
            {
                topNode = topNode->pre;
                delete topNode->next;
                topNode->next = NULL;
                minNode = buttomNode;
                // update minNode
                node* tmp = buttomNode;
                int minN = buttomNode->val;
                while (tmp != NULL)
                {
                    if (tmp->val < minN)
                    {
                        minNode = tmp;
                        minN = minNode->val;
                    }
                    tmp = tmp->next;
                }
            }
            else
            {
                delete topNode;
                topNode = minNode = buttomNode = NULL;
            }
        }
        else
        {
            topNode = topNode->pre;
            delete topNode->next;
            topNode->next = NULL;
        }
    }
    int top() {
        return topNode->val;
    }
    int min() {
        return minNode->val;
    }
    node* topNode;
    node* minNode;
    node* buttomNode;
};