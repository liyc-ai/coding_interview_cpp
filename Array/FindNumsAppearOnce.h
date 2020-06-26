#pragma once
/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/
#include "headers.h"
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
        // 异或
        if (data.size() == 2)
        {
            *num1 = data[0], * num2 = data[1];
            return;
        }
        int res = data[0];
        for (int i = 1; i < data.size(); ++i)
        {
            res ^= data[i];
        }
        int index = 0;
        for (int i = 0;i < sizeof(int); ++i)
        {
            int tmp = res;
            if ((tmp >> i) & 1)
            {
                index = i;
                break;
            }
        }
        int jdg = 1 << index;
        *num1 = 0, * num2 = 0;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data[i] & jdg) *num1 ^= data[i];
            else *num2 ^= data[i];
        }
    }
};