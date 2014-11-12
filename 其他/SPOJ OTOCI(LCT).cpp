#include "stdafx.h"
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
#define  maxn 333333
#define lson ch[x][0]
#define rson ch[x][1]
typedef long long LL;
int pre[maxn], ch[maxn][2], rev[maxn], n, m;
int sz[maxn], val[maxn], sum[maxn];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = ch[i][0] = ch[i][1] = 0;
		rev[i] = 0;
		sz[i] = 1;
	}
}
inline bool not_root(int x)
{
	return (pre[x] != 0 && (ch[pre[x]][0] == x || ch[pre[x]][1] == x));
}
void Reverse(int x)
{
	if (!x) return;
	if (lson) rev[lson] ^= 1;
	if (rson) rev[rson] ^= 1;
	swap(lson, rson);
}
void pushdown(int x)
{
	if (!x) return;
	if (rev[x])
	{
		Reverse(x);
		rev[x] = 0;
	}
}
void pushup(int x)
{
	sz[x] = sz[lson] + sz[rson] + 1;
	sum[x] = val[x] + sum[lson] + sum[rson];
}
void  Rotate(int x, int f)
{
	int y = pre[x];
	ch[y][!f] = ch[x][f];
	if (ch[x][f]) pre[ch[x][f]] = y;
	pre[x] = pre[y];
	if (not_root(y)) ch[pre[y]][ch[pre[y]][1] == y] = x;
	ch[x][f] = y;
	pre[y] = x;
	pushup(y);
}
void Splay(int x)
{
	pushdown(x);
	while (not_root(x))
	{
		if (!not_root(pre[x]))
		{
			pushdown(pre[x]), pushdown(x);
			Rotate(x, ch[pre[x]][0] == x);
		}
		else
		{
			int y = pre[x], z = pre[y];
			pushdown(z), pushdown(y), pushdown(x);
			int f = (ch[z][0] == y);
			if (ch[y][f] == x)
			{
				Rotate(x, !f), Rotate(x, f);
			}
			else
			{
				Rotate(y, f), Rotate(x, f);
			}
		}
	}
	pushup(x);
}
int access(int x)
{
	int v = 0;
	for (; x != 0; x = pre[x])
	{
		Splay(x);
		ch[x][1] = v;
		pushup(v = x);
	}
	return v;
}
int find_root(int x)
{
	for (x = access(x); pushdown(x), ch[x][0] != 0; x = ch[x][0]);
	Splay(x);
	return x;
}
void evert(int x)
{
	rev[access(x)] ^= 1;
	Splay(x);
}
bool link(int x, int y)
{
	if (find_root(x) == find_root(y)) return false;
	evert(x);
	pre[x] = y;
	access(x);
	return true;
}
void update(int x, int d)
{
	evert(x);
	val[x] = d;
	pushup(x);

}
int query(int x, int y)
{
	if (find_root(x) != find_root(y)) return -1;
	evert(x);
	access(y);
	Splay(y);
	return sum[y];
}
void read(int &res)
{
	int  ch, flag = 0;
	res = 0;
	if ((ch = getchar()) == '-')				//判断正负
		flag = 1;
	else if (ch >= '0' && ch <= '9')			//得到完整的数
		res = ch - '0';
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + ch - '0';
	if (flag) res = -res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	while (scanf("%d", &n) != EOF)
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &val[i]);
			sum[i] = val[i];
		}
		scanf("%d", &m);
		while (m--)
		{
			char op[15];
			int x, y;
			scanf("%s%d%d", op, &x, &y);
			if (op[0] == 'b')
			{
				if (!link(x, y)) puts("no"); else puts("yes");
			}
			else if (op[0] == 'p')
			{
				update(x, y);
			}
			else
			{
				int ans = query(x, y);
				if (ans == -1) puts("impossible");
				else printf("%d\n", ans);
			}
		}
	}
	return 0;
}