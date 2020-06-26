#pragma once
/*
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/
#include "headers.h"

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 0) return 0;
        int count = 1;
        deque<int> ugly;
        ugly.push_back(1);
        while (count < index)
        {
            int back = ugly.back();
            int min1, min2, min3;
            for (int i = 0; i < ugly.size(); ++i)
            {
                if (ugly[i] * 2 > back)
                {
                    min1 = ugly[i] * 2;
                    break;
                }
            }
            for (int i = 0; i < ugly.size(); ++i)
            {
                if (ugly[i] * 3 > back)
                {
                    min2 = ugly[i] * 3;
                    break;
                }
            }
            for (int i = 0; i < ugly.size(); ++i)
            {
                if (ugly[i] * 5 > back)
                {
                    min3 = ugly[i] * 5;
                    break;
                }
            }
            ugly.push_back(min(min(min1, min2), min3));
            ++count;
        }
        return ugly.back();
    }
};