
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
LL dp[maxn][4];
int num[maxn];
int new_d(int s, int d)
{
	if (s == 3) return 3;
	int st = s;
	if (d == 6) s++;
	return st==s?0:s;
}
LL dfs(int i, int s,bool e)
{
	if (i == -1) return s == 3;
	if (!e&&~dp[i][s]) return dp[i][s];
	LL ret = 0;
	int u = e ? num[i] : 9;
	for (int d = 0; d <= u; d++)
	{
		ret += dfs(i - 1, new_d(s,d),e&&d == u);
	}
	return e ? ret : dp[i][s] = ret;
}
LL cal(LL n)
{
	int cnt = 0;
	while (n)
	{
		num[cnt++] = n % 10;
		n /= 10;
	}
	return dfs(cnt - 1, 0, 1);
}
LL Bin(LL k)
{
	LL l, r, mid, ans,ret;
	ans = 0;
	l = 666, r = 100000000000LL;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (cal(mid)>= k)
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
	int T;
	scanf("%d", &T);	
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
		LL k;
		scanf("%I64d", &k);
		printf("%I64d\n", Bin(k));
	}
	return 0;
}
