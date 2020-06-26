#pragma once
/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,
可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
测试：
1. 用例:
55

对应输出应该为:16
2. 用例:
10000

对应输出应该为:

4001
*/
#include "headers.h"
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n == 0) return 0;
        int count = 0, tmp = n;
        vector<int> digits, numOne = { 1 };
        while (tmp != 0)
        {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = 2; i < digits.size(); ++i)
        {
            // most 1s of i-digit number to 1;
            numOne.push_back(numOne[i-2] * 10 + (int)pow(10, i - 1));
            //cout << i << ":" << numOne.back() << endl;
        }
        for (int i = digits.size(); i > 1; --i)
        {
            tmp = digits[i - 1];
            n = n % ((int)pow(10, i - 1));
            if (tmp == 1)
            {
                count += numOne[i - 2] + n + 1;
            }
            else if(tmp > 1)
            {
                count += numOne[i - 2] * tmp + (int)pow(10, i - 1);
            }
        }
        if (digits.front() >= 1) count += 1;
        return count;
    }
};
