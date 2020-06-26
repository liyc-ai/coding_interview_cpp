#pragma once
/*
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）
*/
#include "headers.h"

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, bool> chs;
        for (int i = 0; i < str.length(); ++i)
        {
            if (chs.find(str[i]) != chs.end())
            {
                chs[str[i]] = true;
            }
            else
            {
                chs[str[i]] = false;
            }
        }
        for (int i = 0; i < str.length(); ++i)
        {
            if (!chs[str[i]]) return i;
        }
        return -1;
    }
};
