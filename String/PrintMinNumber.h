#pragma once
/*
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/
#include "headers.h"

class Solution {
public:
    int cmp(string& str1, string& str2)
    {
        string s1 = str1 + str2;
        string s2 = str2 + str1;
        return s1 < s2 ? 1 : 0;
    }
    string PrintMinNumber(vector<int> numbers) {
        // using string comparation
        int len = numbers.size();
        vector<string> numS;
        for (int i = 0; i < len; ++i)
        {
            numS.push_back(to_string(numbers[i]));
        }
        // bubble sort, basically
        for (int i = 0; i < len; ++i)
        {
            int index = i;
            for (int j = i + 1; j < len; ++j)
            {
                if (cmp(numS[j], numS[index]))
                {
                    index = j;
                }
            }
            swap(numS[i], numS[index]);
        }
        string ans = "";
        for (int i = 0; i < len; ++i)
        {
            ans += numS[i];
        }
        return ans;
    }
};
