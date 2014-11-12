
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
#include <stack>
#include <string>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111
typedef long long LL;
int dp[maxn*10][maxn][maxn];
int t[maxn*10];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, v;
		char ch;
		scanf("%d%d%d", &n, &v, &m);
		for (int i = 1; i <= n; i++)
		{
			if (i == 1) scanf("%d", &t[i]);
			else scanf(", %d", &t[i]);
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int k = 0; k <=v; k++)
				{
					dp[i][j][k] = dp[i - 1][j][k];
					if (k >= t[i])
					{
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - t[i]] + 1);
						dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][v] + 1);
					}
				}
			}
		}
		printf("%d\n", dp[n][m][v]);
		if (T) printf("\n");

	}
	return 0;
}

