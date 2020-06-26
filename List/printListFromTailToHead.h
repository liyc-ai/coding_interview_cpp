#pragma once
/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/
#include "headers.h"

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> sk;
        while (head)
        {
            sk.push(head->val);
            head = head->next;
        }
        int sz = sk.size();
        vector<int> ans;
        while (sz--)
        {
            ans.push_back(sk.top());
            sk.pop();
        }
        return ans;
    }
};
