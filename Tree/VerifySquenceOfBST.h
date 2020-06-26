#pragma once
/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
测试：
1. 用例:
[4,8,6,12,16,14,10]

对应输出应该为:true
*/

#include "headers.h"

class Solution {
public:
    // recursive
    bool isTree(vector<int>& sequence, int low, int high, int root)
    {
        if (low == high) return true;
        int i, j;
        for (i = low ; i <= high; ++i)
        {
            if (sequence[i] > root) break;
        }
        j = i;
        while (i <= high)
        {
            if (sequence[i] <= root) return false;
            ++i;
        }
        bool left, right;
        if (j == low || j == low + 1) left = true;
        else left = isTree(sequence, low, j - 2, sequence[j - 1]);

        if (j >= high) right = true;
        else right = isTree(sequence, j, high-1, sequence[high]);
        return left && right;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len = sequence.size();
        if (len == 0) return false;
        if (len == 1) return true;
        return isTree(sequence, 0, len - 2, sequence[len - 1]);
    }
};
