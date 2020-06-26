#pragma once
/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0

输入描述：输入一个字符串,包括数字字母符号,可以为空

输入：
+2147483647
1a33

输出：
2147483647
0
*/
#include "headers.h"

class Solution {
public:
    int helper(string str)
    {
        int n = str.length(), ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] < '0' || str[i]>'9') return 0;
            else ans = ans * 10 + (str[i] - '0');
        }
        return ans;
    }
    int StrToInt(string str) {
        int len = str.length(), ans;
        if (len == 0) return 0;
        bool is_neg = false;
        if (str[0] == '-')
        {
            is_neg = true;
            ans = helper(str.substr(1));
        }
        else if (str[0] == '+')
        {
            ans = helper(str.substr(1));
        }
        else {
            ans = helper(str);
        }
        return is_neg ? -1 * ans : ans;
    }
};
