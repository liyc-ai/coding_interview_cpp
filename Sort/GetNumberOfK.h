#pragma once
/*
统计一个数字在排序数组中出现的次数。
测试用例：
[3,3,3,3,4,5],3

对应输出应该为:4
*/
#include "headers.h"

class Solution {
public:
    int biSearch(vector<int>& data, double num)
    {
        int s = 0, e = data.size() - 1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (data[mid] < num) s = mid + 1;
            else if(data[mid] > num) e = mid - 1;
        }
        return s;
    }
    int GetNumberOfK(vector<int> data, int k) {
        // linear search
        /*
        int sz = data.size();
        int count = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (data[i] == k) count++;
            else if (data[i] > k) break;
        }
        return count;
        */
        // binary search
        return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
    }
};