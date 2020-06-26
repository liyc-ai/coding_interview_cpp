#pragma once
/*
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入：输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
测试：
1. 用例:
aabc

对应输出应该为:

["aabc","aacb","abac","abca","acab","acba","baac","baca","bcaa","caab","caba","cbaa"]
*/
#include "headers.h"

class Solution {
public:
    string getNext(string str)
    {
        int len = str.length();
        int i = len - 1, j = len - 1;
        while (i > 0 && str[i] <= str[i - 1]) --i;

        if (i == 0) return "";
        else --i;
        while (str[j] <= str[i]) --j;
        // swap
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        reverse(str.begin() + i + 1, str.end());
        return str;
    }
    vector<string> Permutation(string str) {
        // 字典序算法
        sort(str.begin(), str.end());
        vector<string> ans;
        if (str.length() == 0)
        {
            return ans;
        }
        do {
            ans.push_back(str);
            str = getNext(str);
        } while (str != "");
        return ans;
    }
};
