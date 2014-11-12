
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
#define  maxn 555
LL dp[55][25][maxn];
int num[55][55];
int n;
void dfs(int i, int j, int s)
{
	if (i>= 2 * n - 1) return;
	if (i <n)
	{
		if (dp[i + 1][j - 1][s - num[i][j]])
		{
			printf("L");
			dfs(i + 1, j - 1, s - num[i][j]);
		}
		else
		{
			printf("R");
			dfs(i + 1, j , s - num[i][j]);
		}
	}
	else
	{
		if (dp[i + 1][j][s - num[i][j]])
		{
			printf("L");
			dfs(i + 1, j, s - num[i][j]);
		}
		else
		{
			printf("R");
			dfs(i + 1, j + 1, s - num[i][j]);
		}
	}
}
int main()
{
	int s;
	while (scanf("%d%d",&n,&s)!=EOF)
	{
		if (n==0&&s==0) break;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n - i + 1; j++) scanf("%d", &num[i][j]);
		}
		for (int i = n + 1; i <= 2 * n - 1; i++)
		{
			for (int j = 1; j <= i - n + 1; j++) scanf("%d", &num[i][j]);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) dp[2 * n - 1][i][num[2 * n - 1][i]] = 1;
		for (int i = 2*n-2; i >=n; i--)
		{
			for (int j = 1; j <= i-n+1; j++)
			{
				for (int k = num[i][j]; k <= s; k++)
				{
					 dp[i][j][k] += dp[i + 1][j][k - num[i][j]];
					 dp[i][j][k] += dp[i + 1][j+1][k - num[i][j]];
				}
			}
		}
		LL ans = 0;
		for (int i = n-1; i >=1; i--)
		{
			for (int j = 1; j <= n - i + 1; j++)
			{
				for (int k = num[i][j]; k <= s; k++)
				{
					dp[i][j][k] += dp[i + 1][j][k - num[i][j]];
				    dp[i][j][k] += dp[i + 1][j - 1][k - num[i][j]];
				}
				if (i== 1) ans += dp[1][j][s];
			}
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++)
		{
			if (dp[1][i][s])
			{
				printf("%d ", i - 1);
				dfs(1, i, s);
				break;
			}
		}
		printf("\n");
	}
	return 0;
}

