
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
#include <set>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 1111
typedef long long LL;
int num[maxn];
stack<int>st;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0) break;
		while (scanf("%d", &num[0]) != EOF)
		{
			if (num[0] == 0) break;
			while (!st.empty()) st.pop();
			for (int i = 1; i < n; i++) scanf("%d", &num[i]);
			bool flag = true;
			int cnt = 0,a=1;
			while (cnt<n)
			{
				if (num[cnt] == a)
				{
					a++, cnt++;
				}
				else
				if (!st.empty() && st.top() == num[cnt])
				{
					st.pop();
					cnt++;
				}
				else if (a <= n)
				{
					st.push(a);
					a++;
				}
				else
				{
					flag = false;
					break;
				}
			}
			if (flag) puts("Yes"); else puts("No");
		}
	    puts("");
	}
	return 0;
}

