
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
#define  maxn 211
struct  node 
{
	int x, y, z;
	node(int _x, int _y,int  _z)
	{
		x = _x, y = _y, z = _z;
	}
	node(){}
};
node a[maxn];
int dp[maxn];
bool cmp(node a, node b)
{
	if (a.x == b.x) return a.y > b.y;
	return a.x<b.x;
}
int main()
{
	int n,kase=0;
	while (scanf("%d", &n) != EOF&&n)
	{
		
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[cnt++] = node(x, y, z);
			a[cnt++] = node(x, z, y);
			a[cnt++] = node(y, x, z);
			a[cnt++] = node(y, z, x);
			a[cnt++] = node(z, x, y);
			a[cnt++] = node(z, y, x);
		}
		sort(a+1, a + cnt, cmp);
		memset(dp, 0, sizeof(dp));
		dp[1] = a[1].z;
		for (int i = 2; i < cnt; i++)
		{
			dp[i] = a[i].z;
			for (int j = 1; j < i; j++)
				if (a[i].y > a[j].y) dp[i] = max(dp[i], dp[j] + a[i].z);
		}
		printf("Case %d: maximum height = %d\n", ++kase,*max_element(dp, dp + cnt));
	}
	return 0;
}
