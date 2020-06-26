#pragma once
/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
#include"headers.h"

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int ans, sz = stack1.size();
        for (int i = 0; i < sz - 1; ++i)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        ans = stack1.top();
        stack1.pop();
        for (int i = 0; i < sz - 1; ++i)
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ans;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
