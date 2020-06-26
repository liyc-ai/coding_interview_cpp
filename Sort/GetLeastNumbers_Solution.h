#pragma once
/*
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/
#include "headers.h"

class Solution {
public:
    void my_qSort(vector<int>& input, int low, int high)
    {
        if (low < high)
        {
            int q = partition(input, low, high);
            my_qSort(input, low, q - 1);
            my_qSort(input, q + 1, high);
        }
    }
    int partition(vector<int>& input, int low, int high)
    {
        int x = input[high], i = low - 1, j = low;
        for (j = low; j < high; ++j)
        {
            if (input[j] < x)
            {
                i += 1;
                swap(input[i], input[j]);
            }
        }
        swap(input[i + 1], input[high]);
        return i + 1;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        if (k == 0 || len < k)
        {
            vector<int> ans;
            return ans;
        }
        vector<int> ans(k);
        if (len < k) return ans;
        int q = partition(input, 0, len - 1);
        do {
            if (q + 1 < k)
            {
                q = partition(input, q + 1, input.size() - 1);
            }
            else
            {
                q = partition(input, 0, q - 1);
            }
        } while (q + 1 != k);
        my_qSort(input, 0, k - 1);
        copy(input.begin(), input.begin() + k, ans.begin());
        return ans;
    }
};
