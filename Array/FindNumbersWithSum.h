#pragma once
/*
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。

输出描述：对应每个测试案例，输出两个数，小的先输出。
*/
#include "headers.h"

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        vector<int> ans;
        if (array.empty()) return ans;
        // brute-force
        int sz = array.size();
        for (int i = 0; array[i] < sum/2; ++i)
        {
            if (array[i] > sum / 2) break;
            for (int j = sz - 1; array[j] > sum / 2; --j)
            {
                if (array[i] + array[j] == sum)
                {
                    ans.push_back(array[i]), ans.push_back(array[j]);
                    return ans;
                }
            }
        }
        return ans;
        // hash or double pointer...
    }
};
