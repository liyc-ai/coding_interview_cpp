#pragma once
/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

#include "headers.h"

class Solution {
public:
	void replaceSpace(char* str, int length) {
		if (length == 0) return;
		int count = 0;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ') ++count;
		}
		char* ans = new char[length + 2 * count];
		int j = 0;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
			{
				ans[j] = '%';
				ans[j + 1] = '2';
				ans[j + 2] = '0';
				j += 3;
			}
			else
			{
				ans[j] = str[i];
				j += 1;
			}
		}
		memcpy(str, ans, length + 2 * count);
	}
};
