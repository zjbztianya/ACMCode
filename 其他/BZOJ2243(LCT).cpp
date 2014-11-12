//坑点就是记得取反的时候左右端点颜色也需要交换
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
#define  maxn 111111
#define lson ch[x][0]
#define rson ch[x][1]
typedef long long LL;
int pre[maxn], ch[maxn][2], rev[maxn], n, m;
int sz[maxn], val[maxn], sum[maxn], setv[maxn];
int lc[maxn], rc[maxn];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = ch[i][0] = ch[i][1] = 0;
		rev[i] = 0;
		sz[i] = 1;
		setv[i] = -1;
	}
}
inline bool not_root(int x)
{
	return (pre[x] != 0 && (ch[pre[x]][0] == x || ch[pre[x]][1] == x));
}
void Set(int x, int d)
{
	if (!x) return;
	val[x] = d;
	sum[x] = 1;
	setv[x] = d;
	lc[x] = rc[x] = d;
}
void pushdown(int x)
{
	if (!x) return;
	if (rev[x])
	{
		if (lson)
		{
			rev[lson] ^= 1;
			swap(lc[lson], rc[lson]);
		}
		if (rson)
		{
			rev[rson] ^= 1;
			swap(lc[rson], rc[rson]);
		}
		swap(lson, rson);
		rev[x] = 0;
	}
	if (setv[x] != -1)
	{
		Set(lson, setv[x]);
		Set(rson, setv[x]);
		setv[x] = -1;
	}
}
void pushup(int x)
{
	sz[x] = sz[lson] + sz[rson] + 1;
	lc[x] = rc[x] = val[x];
	if (lson) lc[x] = lc[lson];
	if (rson) rc[x] = rc[rson];
	sum[x] = 1;
	if (lson)
	{
		sum[x] += sum[lson];
		if (rc[lson] == val[x]) sum[x]--;
	}
	if (rson)
	{
		sum[x] += sum[rson];
		if (lc[rson] == val[x]) sum[x]--;
	}

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
    rev[access(x)]^=1;
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
int query(int x, int y)
{
	evert(x);
	access(y);
	Splay(y);
	return sum[y];
}
void update(int x, int y, int d)
{
	evert(x);
	access(y);
	Splay(y);
	val[y] = setv[y] = d;
	lc[y] = rc[y] = d;
	sum[y] = 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	scanf("%d%d", &n, &m);
	init();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &val[i]);
		sum[i] = 1;
		lc[i] = rc[i] = val[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link(u, v);
	}
	while (m--)
	{
		char op[10];
		int a, b, c;
		scanf("%s%d%d", op, &a, &b);
		if (op[0] == 'Q')
		{
			printf("%d\n", query(a, b));
		}
		else
		{
			scanf("%d", &c);
			update(a, b, c);
		}
	}
	return 0;
}