#pragma once
/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/

#include "headers.h"

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int len = pushV.size();
        if (len == 0) return false;
        vector<int> pushed;
        int start = -1;
        for (int i = 0; i < popV.size(); ++i)
        {
            if (pushed.empty() || popV[i] != pushed.back())
            {
                int index;
                if (find(pushV.begin(), pushV.end(), popV[i]) != pushV.end())
                {
                    index = find(pushV.begin(), pushV.end(), popV[i]) - pushV.begin();
                }
                else
                {
                    return false;
                }
                if (index <= start) return false;
                else
                {
                    for (int j = start + 1; j <= index; ++j)
                    {
                        pushed.push_back(pushV[j]);
                    }
                    start = index;
                }
            }
            pushed.pop_back();
        }
        return true;
    }
};