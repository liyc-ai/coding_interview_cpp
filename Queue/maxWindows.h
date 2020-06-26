#pragma once
/*
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}，
{2,3,4,2,6,[2,5,1]}。
*/
#include "headers.h"
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ans;
        int lenNum = num.size();
        if (size == 0 || lenNum<size)
        {
            return ans;
        }

        // brute-force
        /*
        for (int i = 0; i <= lenNum - size; ++i)
        {
            int maxNum = num[i];
            for (int j = i + 1; j < i + size; ++j)
            {
                if (num[j] > maxNum)
                {
                    maxNum = num[j];
                }
            }
            ans.push_back(maxNum);
        }
        return ans;
        */

        // using deque
        // {2,3,4,2,6,2,5,1}
        deque<int> dq;
        for (int i = 0; i < lenNum; ++i)
        {
            while (!dq.empty() && num[dq.back()] < num[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() + size <= i)
            {
                dq.pop_front();
            }
            if (i + 1 >= size) ans.push_back(num[dq.front()]);
        }
        return ans;
    }
};