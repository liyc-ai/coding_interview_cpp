#pragma once
/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007
输入：
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5
*/
#include "headers.h"

class Solution {
private:
	const int kmod = 1000000007;
public:
	int inverHelper(vector<int>& data)
	{
		if (data.size() == 1) return 0;
		if (data.size() == 2)
		{
			if (data[0] > data[1])
			{
				swap(data[0], data[1]);
				return 1;
			}
			else return 0;
		}
		int sz = data.size(), num = 0;
		int leftLen = sz / 2, rightLen = sz - sz / 2;
		vector<int> left(leftLen), right(rightLen);
		copy(data.begin(), data.begin() + leftLen, left.begin());
		copy(data.begin() + leftLen, data.end(), right.begin());
		num += inverHelper(left);
		num += inverHelper(right);
		int i = leftLen - 1, j = rightLen - 1, k = sz - 1;
		// merge
		while (i >= 0 && j >= 0)
		{
			if (left[i] > right[j])
			{
				num = num + j + 1;
				num %= kmod;
				data[k--] = left[i--];
			}
			else  if(left[i] < right[j])
			{
				data[k--] = right[j--];
			}
			else {
				data[k--] = right[j--];
			}
		}
		if (i < 0)
		{
			while (j >= 0) data[k--] = right[j--];
		}
		else if (j < 0)
		{
			while (i >= 0) data[k--] = left[i--];
		}
		return num;
	}
    int InversePairs(vector<int> data) {
		if (data.empty()) return 0;
		// merge sort
		return inverHelper(data) % 1000000007;
    }
};



class Solution {
private:
	const int kmod = 1000000007;
public:
	int InversePairs(vector<int> data) {
		int ret = 0;
		// 在最外层开辟数组
		vector<int> tmp(data.size());
		merge_sort__(data, tmp, 0, data.size() - 1, ret);
		return ret;
	}

	void merge_sort__(vector<int>& arr, vector<int>& tmp, int l, int r, int& ret) {
		if (l >= r) {
			return;
		}

		int mid = l + ((r - l) >> 1);
		merge_sort__(arr, tmp, l, mid, ret);
		merge_sort__(arr, tmp, mid + 1, r, ret);
		merge__(arr, tmp, l, mid, r, ret);
	}

	void merge__(vector<int>& arr, vector<int>& tmp, int l, int mid, int r, int& ret) {
		int i = l, j = mid + 1, k = 0;

		while (i <= mid && j <= r) {
			if (arr[i] > arr[j]) {
				tmp[k++] = arr[j++];
				ret += (mid - i + 1);
				ret %= kmod;
			}
			else {
				tmp[k++] = arr[i++];
			}
		}

		while (i <= mid) {
			tmp[k++] = arr[i++];
		}
		while (j <= r) {
			tmp[k++] = arr[j++];
		}

		for (k = 0, i = l; i <= r; ++i, ++k) {
			arr[i] = tmp[k];
		}
	}

};
