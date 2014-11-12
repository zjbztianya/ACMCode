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
int sz[maxn], val[maxn], maxv[maxn];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = ch[i][0] = ch[i][1] = 0;
		rev[i] = 0;
		sz[i] = 1;
		val[i] = maxv[i] = 0;
	}
}
inline bool not_root(int x)
{
	return (pre[x] != 0 && (ch[pre[x]][0] == x || ch[pre[x]][1] == x));
}
void pushdown(int x)
{
	if (!x) return;
	if (rev[x])
	{
		rev[lson] ^= 1;
		rev[rson] ^= 1;
		swap(lson, rson);
		rev[x] = 0;
	}
}
void pushup(int x)
{
	maxv[x] = val[x];
	if (lson) maxv[x] = max(maxv[lson], maxv[x]);
	if (rson) maxv[x] = max(maxv[rson], maxv[x]);
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
	val[x] += d;
	maxv[x] += d;
	pushup(x);
}
int query(int x, int y)
{
	evert(x);
	access(y);
	Splay(y);
	return maxv[y];
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	scanf("%d", &n);
	init();
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		link(u, v);
	}
	scanf("%d", &m);
	while (m--)
	{
		char op[10];
		int x, y;
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'I')
		{
			update(x, y);
		}
		else
		{
			printf("%d\n", query(x, y));
		}
	}
	return 0;
}