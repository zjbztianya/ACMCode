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
int dp[1 << 12][1 << 12];
int st[133];
int n, m;
int dfs(int sta, int s)
{
	if (dp[sta][s] != INF) return dp[sta][s];
	int cnt = 0;
	for (int i = 0; i < n; i++) if ((sta&st[i]) == s) cnt++;
	if (cnt <= 1) return dp[sta][s] = 0;
	for (int i = 0; i < m; i++)
	{
		if (!(sta&(1 << i)))
		{
			dp[sta][s] = min(dp[sta][s],max(dfs(sta | (1 << i), s | (1 << i)), dfs(sta | (1 << i), s)) + 1);
		}
	}
	return dp[sta][s];
}
int main()
{
	while (scanf("%d%d", &m, &n) != EOF)
	{
		if (n + m == 0) break;
		for (int i = 0; i < n; i++)
		{
			char s[15];
			scanf("%s", s);
			st[i] = 0;
			for (int j = 0; j < m; j++) if (s[j] == '1') st[i] |= (1 << j);
		}
		memset(dp, 0x3f, sizeof(dp));
		printf("%d\n",dfs(0, 0));
	}
}
