#pragma once
/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
*/
#include "headers.h"

class Solution {
public:
    vector<int> getSq(int start, int i)
    {
        vector<int> sq;
        for (int j = start; j < start + i; ++j)
        {
            sq.push_back(j);
        }
        return sq;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        int i = 2;
        vector<vector<int>> ans;
        while (i * (i + 1) / 2 <= sum)
        {
            vector<int> sq;
            if (i % 2 == 1 && sum % i == 0)
            {
                int start = sum / i - i / 2;
                ans.push_back(getSq(start, i));
                
            }
            else if (i % 2 == 0 && sum % i == i/2)
            {
                int start = sum / i - i / 2 + 1;
                ans.push_back(getSq(start, i));
            }
            ++i;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
