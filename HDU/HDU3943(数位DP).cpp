
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
#define maxn 25
typedef long long LL;
LL dp[maxn][maxn][maxn];
LL P, Q, x, y;
int num[maxn];
LL dfs(int i, int sx, int sy, bool e)
{
	if (i == -1)
	{
		if (sx == x&&sy == y) return 1; 
		else return 0;
	}
	if (!e&&~dp[i][sx][sy]) return dp[i][sx][sy];
	LL ret = 0;
	int u = e ? num[i] : 9;
	for (int d = 0; d <= u; d++)
	{
		if (sx == x&&d == 4) continue;
		if (sy == y&&d == 7) continue;
		int a, b;
		a = sx; b = sy;
		if (d == 4) a++;
		if (d == 7) b++;
		ret += dfs(i - 1, a, b, e&&d == u);
	}
	return e ? ret : dp[i][sx][sy] = ret;
}
LL cal(LL n)
{
	int cnt = 0;
	while (n)
	{
		num[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 0, 0, 1);
}
LL Bin(LL k)
{
	LL l, r, mid, ans,ret;
	ans = 0;
	ret = cal(P);
	l = P+1; r = Q;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (cal(mid) - ret>= k)
		{
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}
int main()
{
	int T,kase=0;
	scanf("%d", &T);
	
	while (T--)
	{
		int n;
		memset(dp, -1, sizeof(dp));
		scanf("%I64d%I64d%I64d%I64d", &P, &Q, &x, &y);
		scanf("%d", &n);
		printf("Case #%d:\n", ++kase);
		while (n--)
		{
			LL k;
			scanf("%I64d",&k);
			LL ans = Bin(k);
			if (ans)
			printf("%I64d\n", ans);
			else printf("Nya!\n");
		}
	}
	return 0;
}
