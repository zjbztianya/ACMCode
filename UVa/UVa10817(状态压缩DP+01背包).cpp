
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
int dp[1 << 9][1<<9];
struct  node
{
	int cost;
	int s;
};
node p[155];
int n, m, k,sum;
char str[50];
int cnt[25];
void input(int &s1,int& s2)
{
	memset(cnt, 0, sizeof(cnt));
	sum = 0;
	for (int i = 0; i < n+m; i++)
	{
		scanf("%d", &p[i].cost);
		if (i < n) 
		{
			sum += p[i].cost;
		}
		gets(str);
		int len = strlen(str);
		p[i].s = 0;
		for (int j = 0; j < len; j++)
		{
			if (isdigit(str[j]))
			{
				p[i].s |= (1 << (str[j] - '0'-1));
				if (i < n) cnt[str[j] - '0'-1]++;
			}
		}
		if (i < n) s1 |= p[i].s;
	}
	for (int i = 0; i < k; i++) if (cnt[i] >= 2) s2 |= (1 << i);
}
void DP(int s1,int s2)
{
	dp[s1][s2] = sum;
	for (int i = n; i < n + m; i++)
	{
		for (int sta1 = (1 << k) - 1; sta1 >= 0; sta1--)
		{
			for (int sta2 = (1 << k) - 1; sta2 >= 0; sta2--)
			{
				s1 = sta1 | p[i].s;
				s2 = sta2 | (sta1&p[i].s);
				dp[s1][s2] = min(dp[s1][s2], dp[sta1][sta2] + p[i].cost);
			}
		}
	}
	printf("%d\n", dp[(1 << k) - 1][(1 << k) - 1]);
}
int main()
{
	while (scanf("%d%d%d", &k, &n, &m) != EOF)
	{
		if (k + n + m == 0) break;
		int s1 ,s2 ;
		s1 = s2 = 0;
		input(s1,s2);
		memset(dp, 0x3f, sizeof(dp));
		DP(s1,s2);
	}
	return 0;
}

