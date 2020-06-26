#pragma once
/*
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/
#include "headers.h"

class Solution {
public:
    class Point {
    public:
        Point(int in_row, int in_col, int in_color) :row(in_row), col(in_col), color(in_color) {}

        int get_sum()
        {
            int sum = 0;
            int tmp_row = row, tmp_col = col;
            while (tmp_row != 0)
            {
                sum += (tmp_row % 10);
                tmp_row /= 10;
            }
            while (tmp_col != 0)
            {
                sum += (tmp_col % 10);
                tmp_col /= 10;
            }
            return sum;
        }

        int row;
        int col;
        int color;
    };

    

    int movingCount(int threshold, int rows, int cols)
    {
        if (threshold < 0) return 0;

        // Breadth-first Search
        /*
        queue<Point*> points;
        Point*** grids = new Point ** [rows];
        for (int i = 0; i < rows; ++i)
        {
            grids[i] = new Point * [cols];
            for (int j = 0; j < cols; ++j)
            {
                grids[i][j] = new Point(i, j, 0);
            }
        }
        grids[0][0]->color = 1; // visited, but neightbors may not
        num = 1; 
        points.push(grids[0][0]);
        while (!points.empty())
        {
            Point* tmp = points.front();
            int row = tmp->row, col = tmp->col;
            // four directions
            if (row - 1 >= 0) { // up
                if ((grids[row - 1][col]->color == 0) && (grids[row-1][col]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row - 1][col]->color = 1;
                    points.push(grids[row - 1][col]);
                }
            }
            if (row + 1 < rows) { // down
                if ((grids[row + 1][col]->color == 0) && (grids[row + 1][col]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row + 1][col]->color = 1;
                    points.push(grids[row + 1][col]);
                }
            }
            if (col - 1 >= 0) { // left
                if ((grids[row][col - 1]->color == 0) && (grids[row][col - 1]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row][col - 1]->color = 1;
                    points.push(grids[row][col - 1]);
                }
            }
            if (col + 1 < cols) { // right
                if ((grids[row][col + 1]->color == 0) && (grids[row][col + 1]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row][col + 1]->color = 1;
                    points.push(grids[row][col + 1]);
                }
            }
            tmp->color = 2;
            points.pop();
        }
        return num;
        */

        // Depth-first Search
        
        stack<Point*> points;
        Point*** grids = new Point * *[rows];
        for (int i = 0; i < rows; ++i)
        {
            grids[i] = new Point * [cols];
            for (int j = 0; j < cols; ++j)
            {
                grids[i][j] = new Point(i, j, 0);
            }
        }
        grids[0][0]->color = 1; // visited, but neightbors may not
        num = 1;
        points.push(grids[0][0]);
        while (!points.empty())
        {
            Point* p = points.top();
            int row = p->row, col = p->col;
            // four directions
            if (row - 1 >= 0) { // up
                if ((grids[row - 1][col]->color == 0) && (grids[row - 1][col]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row - 1][col]->color = 1;
                    points.push(grids[row - 1][col]);
                    continue;
                }
            }
            if (row + 1 < rows) { // down
                if ((grids[row + 1][col]->color == 0) && (grids[row + 1][col]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row + 1][col]->color = 1;
                    points.push(grids[row + 1][col]);
                    continue;
                }
            }
            if (col - 1 >= 0) { // left
                if ((grids[row][col - 1]->color == 0) && (grids[row][col - 1]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row][col - 1]->color = 1;
                    points.push(grids[row][col - 1]);
                    continue;
                }
            }
            if (col + 1 < cols) { // right
                if ((grids[row][col + 1]->color == 0) && (grids[row][col + 1]->get_sum() <= threshold))
                {
                    num += 1;
                    grids[row][col + 1]->color = 1;
                    points.push(grids[row][col + 1]);
                    continue;
                }
            }
            p->color = 2;
            points.pop();      
        }
        return num;
    }
 private:
     int num; // number of visited grids
};