#pragma once
/*
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include "headers.h"

class Solution {
public:
    int Add(int num1, int num2)
    {
        int A, B;
        do {
            A = num1 ^ num2;
            B = (num1 & num2) << 1;
            num1 = A, num2 = B;
        } while (B!=0);
        return A;
    }
};
