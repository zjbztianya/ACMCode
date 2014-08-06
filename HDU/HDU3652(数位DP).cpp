
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
LL dp[maxn][15][3];
int num[maxn];
int new_s(int s, int d)
{
	if (s == 2) return 2;
	if (s == 1 && d == 3) return 2;
	if (d == 1) return 1;
	return 0;
}
LL dfs(int i, int s, bool e,int r)
{
	if (i == -1)
	{
		if ((s== 2) && (r== 0)) return 1;
		else return 0;
	}
	if (!e&&~dp[i][r][s]) return dp[i][r][s];
	LL ret = 0;
	int u = e ? num[i] : 9;
	for (int d = 0; d <= u; d++)
	{
		ret += dfs(i - 1,new_s(s,d) , e&&d == u, (r*10+d)%13);
	}
	return e ? ret : dp[i][r][s] = ret;
}
	
LL cal(LL n)
{
	int cnt = 0;
	while (n)
	{
		num[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 0, 1,0);
}
int main()
{
	LL n;
	memset(dp, -1, sizeof(dp));
	while (scanf("%I64d",&n)!=EOF)
	{
		printf("%I64d\n", cal(n));
	}
	return 0;
}
