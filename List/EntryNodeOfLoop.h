#pragma once
/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
测试用例：
1. 用例:
{1,2},{3,4,5}

对应输出应该为: 3
*/
#include "headers.h"

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        // hash map
        map<ListNode*, int> nodes;
        int count = 0;
        nodes[pHead] = count++;
        while (pHead)
        {
            if (!pHead->next) return NULL;
            if (nodes.find(pHead->next) != nodes.end())
            {
                return pHead->next;
            }
            else nodes[pHead->next] = count++;
            pHead = pHead->next;
        }
        return NULL;
    }
};