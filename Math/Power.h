#pragma once
/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

保证base和exponent不同时为0
*/
#include "headers.h"

class Solution {
public:
    double Power(double base, int exponent) {
        // brute-force
        double ans = 1;
        int count = 0;
        while (count < (int)abs(exponent))
        {
            if (exponent > 0)
            {
                ans *= base;
            }
            else
            {
                ans /= base;
            }
            ++count;
        }
        return ans;
    }
};