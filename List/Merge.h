#pragma once
/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL) return pHead2;
		if (pHead2 == NULL) return pHead1;
		// merge
		ListNode* result = NULL, * next = NULL, * nNode;
		while (pHead1 != NULL && pHead2 != NULL)
		{
			if (pHead1->val < pHead2->val)
			{
				nNode = new ListNode(pHead1->val);
				pHead1 = pHead1->next;
			}
			else
			{
				nNode = new ListNode(pHead2->val);
				pHead2 = pHead2->next;
			}
			if (result == NULL)
			{
				result = nNode;
			}
			else
			{
				next->next = nNode;
			}
			next = nNode;
		}
		while (pHead1 != NULL)
		{
			nNode = new ListNode(pHead1->val);
			next->next = nNode;
			next = nNode;
			pHead1 = pHead1->next;
		}
		while (pHead2 != NULL)
		{
			nNode = new ListNode(pHead2->val);
			next->next = nNode;
			next = nNode;
			pHead2 = pHead2->next;
		}
		return result;
	}
};
