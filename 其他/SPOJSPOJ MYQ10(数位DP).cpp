
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
#define maxn 50
typedef long long LL;
LL dp[maxn][maxn];
int num[maxn],tmp[maxn];
LL dfs(int i, int len, bool e,int zero)
{
	if (i == -1) return 1;
	if (!e&&~dp[i][len]) return dp[i][len];
	LL ret = 0;
	int u = e ? num[i] : 9;
	for (int d = 0; d <= u; d++)
	{
		if (d!=0&&d!=1&&d!=8) continue;
		if (zero)
		{
			tmp[i] = d;
			ret += dfs(i - 1, len - !d, e&&d == u, zero&& d == 0);
		}
		else
		{
			int mid = len / 2;
		    int fg = i < mid ? 1 : 0;
			if (fg)
			{
				if (tmp[len - i - 1] == d)
					ret += dfs(i - 1, len, e&&d == u, zero);
			}
			else
			{
				tmp[i] = d;
				ret += dfs(i - 1, len, e&&d == u, zero);
			}
		}
	}
	return e ? ret : dp[i][len] = ret;
}
LL cal(char *s)
{
	int cnt = strlen(s);
	for (int i = 0; i < cnt; i++) num[cnt-i-1] = s[i] - '0';
	return dfs(cnt - 1, cnt, 1,1);
}
int ok(char *s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		if (s[i] != '0'&& s[i] != '8'&&s[i] != '1') return 0;
	for (int i = 0; i < len / 2; i++)
		if (s[i] != s[len - i - 1]) return 0;
	return 1;
}
int main()
{
	int T;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	while (T--)
	{
        char x[maxn], y[maxn];
		scanf("%s%s", x, y);
		printf("%I64d\n", cal(y) - cal(x)+ok(x));
	}
	
	return 0;
}
