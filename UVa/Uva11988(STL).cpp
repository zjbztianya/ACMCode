
#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111111
typedef long long LL;
deque<int>que;
stack<int>st;
char str[maxn];
int main()
{
	while (scanf("%s", str) != EOF)
	{
		int n = strlen(str);
		int flag = 0;
		int i = 0;
		while (i < n && (str[i] == '[' || str[i] == ']')) i++;
		que.push_back(i);
		while (i < n)
		{
			if (str[i] == '[')
			{
				que.push_front(i + 1);
				str[i] = '\0';
			}
			else if (str[i] == ']')
			{
				que.push_back(i + 1);
				str[i] = '\0';
			}
			i++;
		}
		while (!que.empty())
		{
			printf("%s", str + que.front());
			que.pop_front();
		}
		puts("");
	}
	return 0;
}

