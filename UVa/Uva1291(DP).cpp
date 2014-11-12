
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
#define  INF 0x3f3f3f3f
#define  maxn 111111
int dp[maxn][5][5];
int num[maxn];
const int cost[5][5] =
{
	{ 0, 2, 2, 2, 2 },
	{ 0, 1, 3, 4, 3 },
	{ 0, 3, 1, 3, 4 },
	{ 0, 4, 3, 1, 3 },
	{ 0, 3, 4, 3, 1 },
};
int main()
{
	while (scanf("%d", &num[1]) != EOF)
	{
		if (num[1] == 0) break;
		int n = 1;
		while (scanf("%d", &num[++n]) && num[n]);
		--n;
		memset(dp,INF, sizeof(dp));
		dp[1][0][num[1]] = dp[1][num[1]][0] = cost[0][num[1]];
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
					for (int k = 0; k <= 4; k++)
					{
						if (j==k) continue;
						if (dp[i - 1][j][k]==INF) continue;
						dp[i][j][num[i]] = min(dp[i][j][num[i]], dp[i - 1][j][k] + cost[k][num[i]]);
						dp[i][num[i]][k] = min(dp[i][num[i]][k], dp[i - 1][j][k] + cost[j][num[i]]);
					}
			}
		}
		int ans = INF;
		for (int i = 0; i <= 4; i++)
		{
			if (i == num[n]) continue;
			ans = min(ans, min(dp[n][i][num[n]], dp[n][num[n]][i]));
		}
		printf("%d\n", ans);
	}
}

