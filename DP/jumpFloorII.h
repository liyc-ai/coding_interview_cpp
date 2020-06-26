#pragma once
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
#include "headers.h"

class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 0) return 0;
        // dynamic programming
        int* f = new int[number + 1];
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            int now = i;
            while (now != 0)
            {
                f[i] += f[--now];
            }
        }
        return f[number];
    }
};
