#pragma once
/*
输入两个链表，找出它们的第一个公共结点。
（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		// using set
		/*
		set<ListNode*> nodes;
		if (!pHead1 || !pHead2) return NULL;
		while (pHead1)
		{
			nodes.insert(pHead1);
			pHead1 = pHead1->next;
		}
		while (pHead2)
		{
			if (nodes.find(pHead2) != nodes.end()) return pHead2;
			pHead2 = pHead2->next;
		}
		return NULL;
		*/
		// more elegant method
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		while (p1 != p2)
		{
			if (p1 != NULL) p1 = p1->next;
			if (p2 != NULL) p2 = p2->next;
			if (p1 != p2)
			{
				if (p1 == NULL) p1 = pHead2;
				if (p2 == NULL) p2 = pHead2;
			}
		}
		return p1;
	}
};
