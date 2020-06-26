#pragma once
/*
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。
请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，
此时得到的最大乘积是18。
*/
#include "headers.h"

class Solution {
public:
    int cutRope(int number) {
        /*
        // Dynamic Programming
        int* ans = new int[number+1];
        ans[0] = 0; ans[1] = 1;
        for(int i=2; i <= number; ++i)
        {
            ans[i] = 1;
            for(int j=1; j<i;++j) // m>1
            {
                int tmp = max(i-j,ans[i-j])*j;
                ans[i] = max(ans[i],tmp);
            }
        }
        int answer = ans[number];
        delete[] ans; // free memory
        return answer;
        */

        // Greedy Algorithm
        // when n>4, 2*(n-2)>n, 3*(n-3) > n, so the optimal answer contains only 2 and 3
        // 3*2 = 2*3 = 6, 3*3 > 2*2*2, so the number of 2 can not exceed 3
        if (number == 2) return 1;
        if (number == 3) return 2;
        int numThree = number / 3;
        int rst = number % 3;
        if (rst == 1)
        {
            return pow(3, numThree - 1) * 4;
        }
        else if (rst == 2)
        {
            return pow(3, numThree) * 2;
        }
        else
        {
            return pow(3, numThree);
        }
    }
};