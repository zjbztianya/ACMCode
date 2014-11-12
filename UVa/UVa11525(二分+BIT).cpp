
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
#include <sstream>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111111
typedef long long LL;
int c[maxn], num[maxn], n;
int lowbit(int x)
{
	return x&-x;
}
void add(int x, int d)
{
	while (x <= n)
	{
		c[x] += d;
		x += lowbit(x);
	}
}
int query(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n;i++) add(i, 1);
		for (int i = 1; i <= n; i++)
		{
			int l = 1,r = n,ans;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (query(mid) >=num[i]+1)
				{
					r = mid - 1;
					ans = mid;
				}
				else l = mid + 1;
			}
			add(ans, -1);
			if (i == 1) printf("%d", ans); else
			{
				printf(" %d", ans);
			}
		}
		puts("");
	}
	return 0;
}
