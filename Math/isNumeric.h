#pragma once
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"
和"-1E-16"都表示数值。但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
测试用例：
1. "-.123"
结果：true
2. "123.45e+6"
结果：true
*/
#include "headers.h"
class Solution {
public:
    bool isNumeric(char* string)
    {
        set<char> nums = { '0','1','2','3','4','5','6','7','8','9' };
        std::string str(string);
        int sz = str.size();
        int countPoint=0;
        int countE = 0;
        for (int i = 0; i < sz; ++i)
        {
            if (nums.find(str[i]) != nums.end())
            {
                if (i != sz - 1)
                {
                    char ch = str[i + 1];
                    if (!(nums.find(ch) != nums.end() || ch == 'E' || ch == 'e' || ch == '.'))
                        return false;
                }
                else continue;
            }
            if (str[i] == '+' || str[i] == '-')
            {
                if (i == sz - 1) return false;

                char ch = str[i + 1];
                if (!(nums.find(ch) != nums.end() || ch == '.')) return false;
                continue;
            }
            if (str[i] == 'E' || str[i] == 'e')
            {
                ++countE;
                if (countE > 1) return false;
                if (i == sz - 1) return false;
                /*char ch = str[i + 1];
                if (!(nums.find(ch) != nums.end() || ch == '-')) return false;*/
                continue;
            }
            if (str[i] == '.')
            {
                ++countPoint;
                if (countPoint > 1 || countE >=1) return false;
                if (i == sz - 1) return false;

                char ch = str[i + 1];
                if (nums.find(ch) == nums.end()) return false;
                continue;
            }
        }
        return true;
    }
};
