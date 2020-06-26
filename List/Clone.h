#pragma once
/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/
#include "headers.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead) return NULL;
        RandomListNode* nHead = new RandomListNode(pHead->label);
        // copy next and label
        RandomListNode* copyed = nHead, * original = pHead;
        while (pHead->next)
        {
            RandomListNode* node = new RandomListNode(pHead->next->label);
            nHead->next = node;
            pHead = pHead->next;
            nHead = nHead->next;
        }
        nHead = copyed, pHead = original;
        while (nHead)
        {
            RandomListNode* P = original, * N = copyed;
            RandomListNode* ranP = pHead->random;
            while (P != ranP)
            {
                P = P->next;
                N = N->next;
            }
            nHead->random = N;
            pHead = pHead->next;
            nHead = nHead->next;
        }
        return copyed;
    }
};
