#pragma once
/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，
而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

测试用例：
1. 用例:
"aaa","a*a"

对应输出应该为：true
2. 用例:
"aaa","ab*a*c*a"

对应输出应该为：true
*/
#include "headers.h"

class Solution {
public:
    // dynamic programming
    bool matchHelper(string str, string pattern, int i, int j)
    {
        if (i == 0)
        {
            return false;
        }
        if (pattern[j - 1] == '.')
        {
            return true;
        }
        return str[i - 1] == pattern[j - 1];
    }
    bool match(char* str, char* pattern)
    {
        string s_str(str), s_pattern(pattern);
        int sz_str = s_str.size(), sz_pattern = s_pattern.size();
        bool** f = new bool* [sz_str+1];
        if (s_pattern[0] == '*' && sz_pattern==1) return false;
        for (int i = 0; i <= sz_str; ++i)
        {
            f[i] = new bool[sz_pattern+1];
            for (int j = 0; j <= sz_pattern; ++j)
            {
                f[i][j] = false;
            }
        }
        f[0][0] = true;
        for (int i = 0; i <= sz_str; ++i)
        {
            for (int j = 1; j <= sz_pattern; ++j)
            {
                if (s_pattern[j-1] != '*')
                {
                    if (matchHelper(s_str, s_pattern, i, j))
                    {
                        f[i][j] = f[i - 1][j - 1];
                    }
                    else f[i][j] = false;
                }
                else
                {
                    f[i][j] = f[i][j - 2];
                    if (matchHelper(s_str, s_pattern, i, j - 1))
                    {
                        f[i][j] = (f[i][j] || f[i - 1][j]);
                    }
                }
            }
        }
        return f[sz_str][sz_pattern];
    }
};
