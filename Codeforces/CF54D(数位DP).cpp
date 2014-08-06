
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
#define INF 0x3f3f3f3f
#define maxn 2600
typedef long long LL;
LL dp[20][maxn][50];
int num[20];
int lcm[100],tot;
map<int,int>mp;
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
LL dfs(int i, int rmd,int s, bool e)
{
	if (i == -1) return rmd%lcm[s] ? 0 : 1;
	if (!e&&~dp[i][rmd][s]) return dp[i][rmd][s];
	LL ret = 0;
	int u = e ? num[i] : 9;
	for (int d = 0; d <= u; d++)
	{
		ret += dfs(i - 1, (rmd * 10 + d) % 2520, d == 0 ? s : mp[lcm[s]*d / gcd(lcm[s], d)], e&&d == u);
	}
	return e ? ret : dp[i][rmd][s] = ret;
}
LL cal(LL n)
{
	int cnt = 0;
	LL t = n;
	while (n)
	{
		num[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 0, 0, 1);
}
void init()
{
	tot = 0;
	mp.clear();
	for (int i = 1; i <= 2520; i++)
	{
		if (2520 % i == 0)
		{
			mp[i] = tot;
			lcm[tot++] = i;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	init();
	while (T--)
	{
		LL x, y;
		scanf("%I64d%I64d", &x, &y);
		printf("%I64d\n", cal(y) - cal(x - 1));	
	}
	return 0;
}
