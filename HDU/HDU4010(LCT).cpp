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
typedef long long LL;
int pre[maxn], ch[maxn][2], rev[maxn],add[maxn],maxv[maxn],n, m;
int e[maxn][2],sz[maxn],mx,val[maxn];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] = 0;
		ch[i][0] = ch[i][1] = 0;
		rev[i] = 0;
		sz[i] = 1;
		add[i] = 0;
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
		if(ch[x][0]) rev[ch[x][0]] ^= 1;
		if(ch[x][1]) rev[ch[x][1]] ^= 1;
		rev[x] = 0;
		swap(ch[x][0], ch[x][1]);
	}
	if (add[x])
	{
		if (ch[x][0])
		{
			add[ch[x][0]] += add[x];
			maxv[ch[x][0]] += add[x];
			val[ch[x][0]] += add[x];
		}
		if (ch[x][1])
		{
			add[ch[x][1]] += add[x];
			maxv[ch[x][1]] += add[x];
			val[ch[x][1]] += add[x];
		}
		add[x] = 0;
	}
}
void pushup(int x)
{
	sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
	maxv[x] = val[x];
	maxv[x] = max(maxv[x], maxv[ch[x][0]]);
	maxv[x] = max(maxv[x], maxv[ch[x][1]]);
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
inline int access(int x)
{
	int v = 0;
	for (; x != 0; x = pre[x])
	{
		Splay(x);
		ch[x][1] = v;
		pushup(v=x);
	}
	return v;
}
inline int find_root(int x)
{
	for (x = access(x); pushdown(x), ch[x][0] != 0; x = ch[x][0]);
	Splay(x);
	return x;
}
inline void evert(int x)
{
	rev[access(x)] ^= 1;
	Splay(x);
}
inline bool link(int x, int y)
{
	if (find_root(x) == find_root(y)) return false;
	evert(x);
	pre[x] = y;
	access(x);
	return true;
}
inline bool cut(int x, int y)
{
	if (x == y || find_root(x) != find_root(y)) return false;
	evert(x);
	access(y);
	Splay(y);
	pre[ch[y][0]] = 0;
	ch[y][0] = 0;
	pushup(y);
	return true;
}
bool update(int x, int y, int w)
{
	if (find_root(x) != find_root(y)) return false;
	evert(x);
	access(y);
	Splay(y);
	add[y] += w;
	maxv[y] += w;
	val[y] += w;
	return true;
}
bool query(int x, int y)
{
	if (find_root(x) != find_root(y)) return false;
	evert(x);
	access(y);
	Splay(y);
	mx = maxv[y];
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	while (scanf("%d",&n)!=EOF)
	{
		init();
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d%d", &e[i][0], &e[i][1]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &val[i]);
			maxv[i] = val[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			int u = e[i][0], v = e[i][1];
			link(u, v);
		}
		scanf("%d", &m);
		while (m--)
		{
			int op, x, y, w;
			scanf("%d", &op);
			if (op == 1)
			{
				scanf("%d%d", &x, &y);
				if (!link(x, y)) puts("-1");
			}
			else if (op == 2)
			{
				scanf("%d%d", &x, &y);
				if (!cut(x, y))puts("-1");
			}
			else if (op == 3)
			{
				scanf("%d%d%d", &w, &x, &y);
				if (!update(x, y, w)) puts("-1");
			}
			else
			{
				scanf("%d%d", &x, &y);
				if (!query(x, y)) puts("-1");
				else printf("%d\n", mx);
			}
		}
		puts("");
	}
	return 0;
}