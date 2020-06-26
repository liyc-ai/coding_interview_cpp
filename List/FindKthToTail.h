#pragma once
/*
输入一个链表，输出该链表中倒数第k个结点。
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
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (!pListHead) return NULL;
		int len = 0;
		ListNode* head = pListHead;
		while (head)
		{
			++len;
			head = head->next;
		}
		int count = 0;
		if (len >= k)
		{
			while (pListHead)
			{
				++count;
				if (count < len-k+1)
				{
					pListHead = pListHead->next;
				}
				else
				{
					// pListHead->next = NULL;
					return pListHead;
				}
			}
		}
		return NULL;
	}
};