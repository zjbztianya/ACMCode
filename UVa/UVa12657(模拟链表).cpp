// GO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 111111
typedef long long LL;
int nxt[maxn], pre[maxn];
void init(int n)
{
	for (int i = 1; i <= n;i++)
	{
		pre[i] = i - 1;
		nxt[i] = i + 1;
	}
	nxt[n] = 0;
	nxt[0] = 1; pre[0] = n;
}
void link(int l, int r)
{
	pre[r] = l; nxt[l] = r;
}
int main()
{
	int n, m,kase=0;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int rev = 0;
		init(n);
		while (m--)
		{
			int op, x, y;
			scanf("%d", &op);
			if (op == 4) rev = 1 - rev;
			else
			{
				scanf("%d%d", &x, &y);
				if ((op == 1 || op == 2) && rev) op = 3 - op;
				if (op == 3&&nxt[y] == x) swap(x, y);
				int lx, rx, ly, ry;
				lx = pre[x]; rx = nxt[x];
				ly = pre[y]; ry = nxt[y];
				if (op == 1)
				{
					if (nxt[x]==y) continue;
					link(lx, rx);
					link(ly, x);
					link(x, y);
                                                            
				}
				else if (op == 2)
				{
					if (nxt[y]==x) continue;
					link(lx, rx);
					link(x, ry);
					link(y, x);
				}
				else
				{
					if (nxt[x] == y)
					{
						link(lx, y);
						link(y, x);
						link(x, ry);
					}
					else
					{
						link(lx, y);
						link(y, rx);
						link(ly, x);
						link(x, ry);
					}
				}
			}
		}
		if (rev)
		{
			for (int i = 1; i <= n; i++) swap(pre[i], nxt[i]);
		}
		int pos;
		for (int i = 1; i <= n; i++)
		{
			if (pre[i] == 0)
			{
				pos = i;
				break;
			}
		}
		int cnt = 1;
		LL ans = 0;
		while (pos!=0)
		{
			if (cnt & 1) ans += pos;
			pos = nxt[pos];
			cnt++;
		}
		printf("Case %d: %I64d\n", ++kase,ans);
	}
	return 0;
}




