
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
LL dp[2][15555], sum[15555];
int main()
{
	int T,kase=0;
	scanf("%d", &T);
	while (T--)
	{
        int n, k, s;
		scanf("%d%d%d", &n, &k, &s);
		memset(dp, 0, sizeof(dp));
		sum[0] = 0;
		for (int i = 1; i <= k; i++) dp[1][i] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= s; j++) sum[j] = (sum[j - 1] + dp[(i + 1) & 1][j])%MOD;
			memset(dp, 0, sizeof(dp));
			for (int j = i; j <= i*k && j<=s; j++)
				if(j-k-1>=0) dp[i&1][j] = ((sum[j - 1] - sum[j - k - 1])%MOD+MOD)%MOD;
				else
				{
					dp[i & 1][j] = sum[j - 1];
				}
		}
		printf("Case %d: %I64d\n", ++kase, dp[n & 1][s]);
	}
	return 0;
}

