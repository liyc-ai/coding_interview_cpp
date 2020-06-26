#pragma once
/*
输入一个链表，反转链表后，输出新链表的表头。
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
	ListNode* ReverseList(ListNode* pHead) {
		if (!pHead) return pHead;
		ListNode* pTail = NULL, * tail = NULL;
		vector<int> nums;
		while (pHead)
		{
			nums.push_back(pHead->val);
			pHead = pHead->next;
		}
		for (int i = nums.size() - 1; i >= 0; --i)
		{
			ListNode* next = new ListNode(nums[i]);
			if (tail != NULL)
			{
				tail->next = next;
			}
			else
			{
				pTail = next;
			}
			tail = next;
		}
		return pTail;
	}
};
