#pragma once
/*
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/
#include "headers.h"

class Solution {
public:
    int  NumberOf1(int n) {
        int len = sizeof(int)*8;
        int count = 0;
        while (len--)
        {
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }
};
