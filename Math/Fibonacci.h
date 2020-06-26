#pragma once
/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        if (n == 0) return 0;
        int pre1 = 0, pre2 = 1;
        for (int i = 2; i <= n; ++i)
        {
            int rhd = pre2;
            pre2 += pre1;
            pre1 = rhd;
        }
        return pre2;
    }
};
