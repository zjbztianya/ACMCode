
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
#include <set>
#include <sstream>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 222222
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
int num[maxn];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			if (l>r) swap(l, r);
			if (r - l + 1>10000)
			{
				puts("0");
				continue;
			}
			int mp[10004];
			memset(mp, 0, sizeof(mp));
			int ans = INF,mx,mi;
			mx = 0, mi = INF;
			for (int i = l; i <= r; i++)
			{
				if (mp[num[i]])
				{
					ans = 0;
					break;
				}
				mp[num[i]]++;
				mx = max(mx, num[i]);
				mi = min(mi, num[i]);
			}
			int pre = mi;
			for (int i = mi + 1; i <= mx; i++)
			{
				if (mp[i])
				{
					ans = min(ans, i - pre);
					pre = i;
				}
			}
			printf("%d\n", ans);
		}

	}
	return 0;
}
