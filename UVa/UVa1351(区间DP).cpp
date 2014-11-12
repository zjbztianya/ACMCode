
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
#define  maxn 222
#define  INF 0x3f3f3f3f
int dp[maxn][maxn];
char str[maxn];
bool check(int l,int r,int d)
{
	if ((r - l + 1) % d) return false;
	for (int  i = 1; i <(r-l+1)/d; i++)
	{
		int st = l + i*d;
		for (int j = 0; j <d; j++)
			if (str[st+j] != str[st+j-d]) return false;
	}
	return true;
}
int getsum(int n)
{
	int ret = 0;
	while (n)
	{
		ret ++;
		n /= 10;
	}
	return ret;
}
int dfs(int i, int j)
{
	if (i > j) return 0;
	if (i == j) return dp[i][j]=1;
	if (dp[i][j] != INF) return dp[i][j];
	for (int k = i; k < j; k++) 
	{
		dp[i][j] = min(dp[i][j], dfs(i, k) + dfs(k + 1, j));
	}
	int len = (j - i + 1) / 2;
	for (int k = 1; k <= len; k++)
	{
		if (check(i, j, k))
		{
			dp[i][j] = min(dp[i][j], dfs(i, i + k - 1) + 2 + getsum((j - i + 1) / k));
		}
	}
	return dp[i][j];
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str+1);
		int n = strlen(str+1);
		memset(dp, 0x3f, sizeof(dp));
		printf("%d\n",dfs(1, n));
	}
	return 0;
}

