#pragma once
/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include "headers.h"

class Solution {
public:
    void reOrderArray(vector<int>& array) {
        int len = array.size();
        if (len <= 0) return;
        int i = -1, j = 0;
        while (j < len)
        {
            if (array[j] & 1)
            {
                i += 1;
                array.insert(array.begin() + i, array[j]);
                array.erase(array.begin() + j + 1);
            }
            ++j;
        }
    }
};