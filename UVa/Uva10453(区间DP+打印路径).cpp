
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
#define  maxn 1111
#define  INF 0x3f3f3f3f
int dp[maxn][maxn];
char str[maxn];
int dfs(int i, int j)
{
	if (i > j) return 0;
	if (i == j) return dp[i][j] = 0;
	if (dp[i][j] != INF)return dp[i][j];
	if (str[i] == str[j]) dp[i][j] = dfs(i + 1, j - 1);
	else
	dp[i][j] = min(dfs(i + 1, j), dfs(i, j - 1)) + 1;
	return dp[i][j];
}
void print(int l, int r)
{
	if (l > r) return;
	if (l == r)
	{
		printf("%c", str[r]);
	}
	else
	if (str[l] == str[r])
	{
		printf("%c", str[l]);
		print(l + 1, r - 1);
		printf("%c", str[r]);
	}
	else if (dp[l][r - 1] < dp[l + 1][r])
	{
		printf("%c", str[r]);
		print(l, r - 1);
		printf("%c", str[r]);
	}
	else
	{
		printf("%c", str[l]);
		print(l + 1, r);
		printf("%c", str[l]);
	}

}
int main()
{
	while (scanf("%s", str + 1) != EOF)
	{
		int n = strlen(str + 1);
		memset(dp, INF, sizeof(dp));
		printf("%d ", dfs(1, n));
		print(1, n);
		printf("\n");
	}
	return 0;
}

