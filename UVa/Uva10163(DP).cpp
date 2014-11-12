
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
using namespace std;
typedef long long LL;
#define  MOD 100000007
#define  maxn 111
#define  INF 0x3f3f3f3f
int dp[maxn][maxn],p[maxn];
int dfs(int i, int j)
{
	if (j == 0) return dp[i][j] = INF;
	if (i == 1) return dp[i][j] = p[i] / j;
	if (~dp[i][j])return dp[i][j];
	for (int k = 0; k <= j; k++) dp[i][j] = max(dp[i][j], min(dfs(i - 1, k), j - k > 0 ? (p[i] / (j - k)) : INF));
	return dp[i][j];
}
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n + m == 0) break;
		for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
		memset(dp, -1, sizeof(dp));
		int L=dfs(m,n);
		printf("%d ", L);
		if (L == 0)
		{
			printf("0\n");
			continue;
		}
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i <= m; i++) dp[i][0] = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dp[i][j] = dp[i - 1][j];
				for (int k = 1; k <= j; k++)
				{
					if (p[i] / k >= L)
						dp[i][j] = min(dp[i][j],dp[i - 1][j - k] + p[i]);
				}
			}
		}
		printf("%d\n", dp[m][n]);
	}
	return 0;
}

