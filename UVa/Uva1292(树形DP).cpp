
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
#define  maxn 1555
#define  INF 0x3f3f3f3f
int dp[maxn][2];
vector<int>G[maxn];
int deg[maxn];
void dfs(int u)
{
	int n = G[u].size();
	if (n == 0)
	{
		dp[u][0] = 0;
		dp[u][1] = 1;
		return;
	}
	dp[u][0] = 0;
	dp[u][1] = 1;
	for (int i = 0; i < n; i++)
	{
		int v = G[u][i];
		dfs(v);
	}
	for (int i = 0; i < n; i++)
	{
		int v = G[u][i];
		dp[u][0] += dp[v][1];
		dp[u][1] +=min(dp[v][0] ,dp[v][1]);
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i = 0; i < n; i++) G[i].clear();
		memset(deg, 0, sizeof(deg));
		for (int i = 0; i < n; i++)
		{
			int u, v, cnt;
			scanf("%d:(%d)", &u, &cnt);
			for (int j = 0; j < cnt; j++)
			{
				scanf("%d", &v);
				G[u].push_back(v);
				deg[v]++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (!deg[i])
			{
				dfs(i);
				printf("%d\n", min(dp[i][0], dp[i][1]));
				break;
			}
		}
	}
	return 0;
}

