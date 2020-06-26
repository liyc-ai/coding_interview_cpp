#pragma once
/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
测试用例：
1. { 1,1,2,2,3,3,4,4 }
结果：{}
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        // pHead is special
        if (pHead == NULL) return NULL;
        if (pHead->next == NULL) return pHead;
        ListNode* pNext = pHead->next;
        while (pNext && pHead->val == pNext->val)
        {
            while (pNext)
            {
                if (pHead->val == pNext->val)
                {
                    pHead = pNext;
                    pNext = pNext->next;
                }
                else break;
            }
            pHead = pHead->next;
            if (!pHead) return NULL;
            pNext = pHead->next;
        }
        // the list is ordered
        ListNode* parent = pHead;
        while (pNext != NULL)
        {
            ListNode* rhd = pNext->next;
            if (rhd && rhd->val == pNext->val)
            {
                while (rhd)
                {
                    if (pNext->val == rhd->val)
                    {
                        pNext = rhd;
                        rhd = rhd->next;
                    }
                    else break;
                }
                parent->next = pNext->next;
            }
            else parent = pNext;
            pNext = pNext->next;
        }
        return pHead;
    }
};
