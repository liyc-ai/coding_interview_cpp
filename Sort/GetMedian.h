#pragma once
/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。
*/
#include "headers.h"

class Solution {
public:
    // binary search, increasing
    /*
    void Insert(int num)
    {
        int len = readNum.size();
        int left = 0, right = len - 1, mid = (len-1)/ 2;
        if (len == 0)
        {
            readNum.insert(readNum.begin(), num);
            return;
        }
        if (readNum[right] <= num)
        {
            readNum.insert(readNum.end(), num);
            return;
        }
        while (left < mid)
        {
            if (readNum[mid] == num)
            {
                break;
            }
            else if (readNum[mid] > num)
            {
                right = mid;
            }
            else {
                left = mid;
            }
            mid = (left + right) / 2;
        }
        if (readNum[mid] >= num)
        {
            readNum.insert(readNum.begin() + mid, num);
        }
        else {
            readNum.insert(readNum.begin() + mid + 1, num);
        }
    }

    double GetMedian()
    {
        int len = readNum.size();
        if (len % 2) return readNum[len / 2];
        else return (readNum[len / 2] + readNum[len / 2 - 1]) / 2;
    }
    vector<double> readNum;
    */
    
    // heap
    void Insert(int num)
    {
        ++cnt;
        if (cnt & 1) // odd, push left
        {
            if (!min_q.empty() && num > min_q.top())
            {
                min_q.push(num);
                num = min_q.top();
                min_q.pop();
            }
            max_q.push(num);
        }
        else { // even, push right
            if (!max_q.empty() && num < max_q.top())
            {
                max_q.push(num);
                num = max_q.top();
                max_q.pop();
            }
            min_q.push(num);
        }
    }

    double GetMedian()
    {
        if (cnt & 1)
        {
            return max_q.top();
        }
        else return (static_cast<double>(min_q.top()) + static_cast<double>(max_q.top())) / 2;
    }

    priority_queue<int, vector<int>, less<int>> max_q; // left
    priority_queue<int, vector<int>, greater<int>> min_q; // right

    int cnt;
};
