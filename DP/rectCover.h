#pragma once
/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
#include "headers.h"

class Solution {
public:
    int rectCover(int number) {
        if (number == 0) return 0;
        // dynamic programming
        int* f = new int[number + 1];
        f[0] = 1, f[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[number];
    }
};
