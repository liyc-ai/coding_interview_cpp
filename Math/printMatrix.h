#pragma once
/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
#include "headers.h"

class Solution {
public:
    vector<int> helper(vector<vector<int>> matrix)
    {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans; // row
        int n = matrix[0].size();
        if (n == 0) return ans; // col
        // up
        if (!matrix.empty() && !matrix[0].empty())
        {
            for (int i = 0; i < n; ++i)
            {
                ans.push_back(matrix[0][i]);
            }
            matrix.erase(matrix.begin());
            --m;
        }
        // right
        if (!matrix.empty() && !matrix[0].empty())
        {
            for (int i = 0; i < m; ++i)
            {
                ans.push_back(matrix[i][n - 1]);
                matrix[i].erase(matrix[i].begin() + n - 1);
            }
            --n;
        }
        // down
        if (!matrix.empty() && !matrix[0].empty())
        {
            for (int i = n - 1; i >= 0; --i)
            {
                ans.push_back(matrix[m - 1][i]);
            }
            matrix.pop_back();
            --m;
        }
        // left
        if (!matrix.empty() && !matrix[0].empty())
        {
            for (int i = m - 1; i >= 0; --i)
            {
                ans.push_back(matrix[i][0]);
                matrix[i].erase(matrix[i].begin());
            }
            --n;
        }
        vector<int> res = helper(matrix);
        if (res.empty()) return ans;
        else
        {
            for (int i = 0; i < res.size(); ++i)
            {
                ans.push_back(res[i]);
            }
        }
        return ans;
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        return helper(matrix);
    }
};