
#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 30
typedef long long LL;
LL dp[maxn][10];
int num[maxn];
LL dfs(int i, int s, bool e,int pre)
{
	if (i == -1) return s == 1;
	if (!e&&~dp[i][pre]&&s) return dp[i][pre];
	LL ret = 0;
	int u = e ? num[i] : 9;
	for (int d = 0; d <= u; d++)
	if(!s||abs(pre-d)>=2)
	{
		ret += dfs(i - 1, s||d>0, e&&d == u, d);
	}
	if (!e&&s)dp[i][pre] = ret;
	return ret;
}
	
LL cal(LL n)
{
	int cnt = 0;
	while (n)
	{
		num[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 0, 1,11);
}
int main()
{
	LL x,y;
	memset(dp, -1, sizeof(dp));
	while (scanf("%I64d%I64d", &x,&y)!=EOF)
	{
		printf("%I64d\n", cal(y)-cal(x-1));
	}
	return 0;
}
