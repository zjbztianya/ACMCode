
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
typedef long long LL;
int fa[maxn], sz[maxn],sum[maxn];
int mp[maxn];
int tot;
int cha(int x)
{
	return fa[x] == x ? x : fa[x] = cha(fa[x]);
}
int main()
{
	freopen("in.txt", "r", stdin);
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i <maxn; i++)
		{
			fa[i] = i;
			sz[i] = 1;
			sum[i] = i;
			mp[i] = i;
		}
		tot = n; 
		while (m--)
		{
			int op, u, v;
			scanf("%d", &op);
			if (op==1)
			{
				scanf("%d%d", &u, &v);
				int fu = cha(mp[u]), fv = cha(mp[v]);
				if (fu!=fv)
				{
					fa[fu] = fv;
					sz[fv] += sz[fu];
					sum[fv] += sum[fu];
				}
			}
			else if (op == 2)
			{
				scanf("%d%d", &u, &v);
				int fu = cha(mp[u]), fv = cha(mp[v]);
				if (fu != fv)
				{
					sz[fu]--;
					sum[fu] -= u;
					mp[u] = ++tot;
					fa[tot] = fv;
					sz[fv]++;
					sum[fv] += u;
				}
			}
			else
			{
				scanf("%d", &u);
				int f = cha(mp[u]);
				printf("%d %d\n", sz[f], sum[f]);
			}
		}
	}
	return 0;
}
