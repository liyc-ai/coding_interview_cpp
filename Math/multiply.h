#pragma once
/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
（注意：规定B[0] = A[1] * A[2] * ... * A[n-1]，B[n-1] = A[0] * A[1] * ... * A[n-2];）
*/
#include "headers.h"

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        int* forward = new int[n], * backward = new int[n];
        forward[0] = 1, backward[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            forward[i] = A[i-1] * forward[i - 1];
            backward[i] = A[n - i] * backward[i - 1];
        }

        vector<int> B;
        for (int i = 0; i < n; ++i)
        {
            B.push_back(forward[i] * backward[n-i-1]);
        }
        return B;
    }
};
