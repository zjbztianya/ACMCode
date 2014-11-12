
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
#include <cstdlib>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 55555
typedef long long LL;
struct node
{
	char s[15];
	int xc, yc, a, b, c;
};
node op[maxn];
int col[10], fa[maxn], m, n,cnt;
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	while (scanf("%d%d%d", &n, &m,&cnt) != EOF)
	{
		for (int i = 0; i < cnt; i++)
		{
			scanf("%s%d%d%d%d", &op[i].s, &op[i].xc, &op[i].yc, &op[i].a, &op[i].b);
			if (op[i].s[0] == 'R') scanf("%d", &op[i].c);
		}
		memset(col, 0, sizeof(col));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= m; j++) fa[j] = j;
			for (int j = cnt - 1; j >= 0; j--)
			{
				int l, r, color;
				if (op[j].s[0] == 'C')
				{
					color = op[j].b;
					if ((i - op[j].xc)*(i - op[j].xc) > op[j].a*op[j].a) continue;
					int len = (int)(sqrt((op[j].a*op[j].a - (i - op[j].xc)*(i - op[j].xc))+1e-20));
					l = max(0, op[j].yc - len);
					r = min(op[j].yc + len, m - 1);
				}
				else if (op[j].s[0] == 'D')
				{
					color = op[j].b;
					if (abs(i - op[j].xc) > op[j].a)continue;
					int len = op[j].a - abs(i - op[j].xc);
					l = max(0, op[j].yc - len);
					r = min(op[j].yc + len, m - 1);
				}
				else if (op[j].s[0] == 'R')
				{
					color = op[j].c;
					if (i<op[j].xc || i>op[j].xc + op[j].a - 1) continue;
					l = max(0, op[j].yc);
					r = min(op[j].yc + op[j].b - 1, m - 1);
				}
				else
				{
					color = op[j].b;
					if (i < op[j].xc || i >= op[j].xc + (op[j].a + 1) / 2) continue;
					int len = (op[j].a + 1) / 2 - (i - op[j].xc) - 1;
					l = max(0,op[j].yc - len);
					r = min(m-1,op[j].yc + len);
				}
				l = find(l);
				while (l <= r)
				{
					col[color]++;
					fa[l] = l + 1;
					l = find(l + 1);
				}
			}
		}
		for (int i = 1; i < 9; i++) printf("%d ", col[i]);
		printf("%d\n", col[9]);
	}
	return 0;
}
