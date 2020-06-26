#pragma once
/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/
#include "headers.h"

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if (len == 0) return 0;
        map<int, int> times;
        for (int i = 0; i < len; ++i)
        {
            if (times.find(numbers[i]) != times.end())
            {
                times[numbers[i]] += 1;
            }
            else
            {
                times[numbers[i]] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            if (times[numbers[i]] > len / 2)
            {
                ans = numbers[i];
            }
        }
        return ans;
    }
};
