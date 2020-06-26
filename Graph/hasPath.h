#pragma once
/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。

*/
#include "headers.h"

class Solution {
public:
    class Point {
    public:
        Point(int in_row, int in_col, int in_color, char in_ch) :
            row(in_row), col(in_col), color(in_color), ch(in_ch){}


        int row;
        int col;
        char ch;
        int color;
    };

    bool out_range(int r, int c, int row, int col)
    {
        if ((row + r < 0) || (row + r >= self_rows)) return true;
        if ((col + c < 0) || (col + c >= self_cols)) return true;
        return false;
    }

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        string new_str(str);
        self_rows = rows, self_cols = cols;

        // dfs for possible paths
        // initialize
        stack<Point*> points;
        Point*** grids = new Point * *[self_rows];
        for (int l = 0; l < self_rows; ++l)
        {
            grids[l] = new Point * [self_cols];
            for (int m = 0; m < self_cols; ++m)
            {
                grids[l][m] = new Point(l, m, 0, matrix[l * self_cols + m]);
            }
        }
        
        int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
        for (int i = 0; i < self_rows; ++i)
        {
            for (int j = 0; j < self_cols; ++j)
            {
                if (grids[i][j]->ch != new_str[0]) continue;
                // clear
                for (int l = 0; l < self_rows; ++l)
                {
                    for (int m = 0; m < self_cols; ++m)
                    {
                        grids[l][m]->color = 0;
                    }
                }

                // start to search
                int pos = 1;
                grids[i][j]->color = 1;
                points.push(grids[i][j]);

                while (!points.empty())
                {
                    if (pos == new_str.length()) return true;
                    Point* p = points.top();
                    int row = p->row, col = p->col;
                    // four directions
                    bool is_all = true;
                    for (int r = 0; r < 4; ++r)
                    {
                        if ((!out_range(dir[r][0], dir[r][1], row, col)) && (grids[row + dir[r][0]][col + dir[r][1]]->color==0))
                        {
                            if (new_str[pos] == grids[row + dir[r][0]][col + dir[r][1]]->ch)
                            {
                                grids[row + dir[r][0]][col + dir[r][1]]->color = 1;
                                points.push(grids[row + dir[r][0]][col + dir[r][1]]);
                                ++pos;
                                is_all = false;
                                break;
                            }
                        }
                    } 
                    if (is_all)
                    {
                        p->color = 2;
                        points.pop();
                        --pos;
                    }
                }
            }
        }
        return false;
    }
    private:
        int self_rows, self_cols;
};
