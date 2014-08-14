

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
using namespace std;
#define  maxn 11111
int sg[maxn];
bool vis[maxn];
int SG(int x)
{
	if (x == 1 || x == 2) return 0;
	if (sg[x] != -1) return sg[x];
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= x / 2; i++)
		if (i != x - i)
		{
		    vis[SG(i) ^ SG(x - i)] = true;
		}
	for (int i = 0;; i++)
		if (!vis[i])
		{
		   sg[x] = i;
		   break;
		}
	return sg[x];
}
int main()
{
	int T, kase = 0;
	scanf("%d", &T);
	memset(sg, -1, sizeof(sg));
	sg[1] = sg[2] = 0;
	for (int i = 1; i <= 10000; i++)
	{
		sg[i] = SG(i);
	}
	while (T--)
	{
		int n, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			ans ^= sg[x];
		}
		printf("Case %d: ", ++kase);
		if (ans)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}

