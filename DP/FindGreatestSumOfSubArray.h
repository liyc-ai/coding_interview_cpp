#pragma once
/*
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,
并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
测试：
1. 用例:
[1,-2,3,10,-4,7,2,-5]

对应输出应该为: 18
*/
#include "headers.h"

class Solution {
public:
    /*
    // see CLRS 4.1
    // recursive method
    int cross(vector<int>& array, int low, int mid, int high)
    {
        int sum = 0, left = INT_MIN, right = INT_MIN;
        for (int i = mid; i >= low; --i)
        {
            sum += array[i];
            if (sum > left) left = sum;
        }
        sum = 0;
        for (int i = mid + 1; i <= high; ++i)
        {
            sum += array[i];
            if (sum > right) right = sum;
        }
        return left + right;
    }
    int helper(vector<int>& array, int low, int high)
    {
        if (low == high) return array[low];
        int mid = (low+high) / 2;
        int leftM = helper(array, low, mid);
        int rightM = helper(array, mid + 1, high);
        int crossM = cross(array, low, mid, high);
        return max(max(leftM, rightM), crossM);
    }
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        if (len == 0) return 0;
        return helper(array, 0, len - 1);
    }
    */
    // dynamic-programming
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size();
        if (sz == 0) return 0;
        int** endR = new int* [sz];
        for (int i = 0; i < sz; ++i) endR[i] = new int[sz];
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                if (i == j) endR[i][j] = array[i];
                else {
                    if (endR[i][j - 1] > 0) endR[i][j] = endR[i][j - 1] + array[j];
                    else endR[i][j] = array[j];
                }
            }
        }
        int* f = new int[sz];
        f[0] = array[0];
        for (int i = 1; i < sz; ++i)
        {
            f[i] = f[i - 1];
            for (int k = 0; k <= i; ++k)
            {
                if (endR[k][i] > f[i]) f[i] = endR[k][i];
            }
        }
        return f[sz - 1];
    }
};
