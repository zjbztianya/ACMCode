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
#define  maxn 111111
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
struct node
{
	int to,next;
};
node edge[maxn << 1];
int head[maxn], tot;
int top[maxn];//top[v]表示v所在的重链的顶端节点
int fa[maxn]; //父亲节点
int dep[maxn];//深度
int sz[maxn];//sz[v]表示以v为根的子树的节点数
int id[maxn];//id[v]表示v与其父亲节点的连边在线段树中的位置
int son[maxn];//重儿子
int pos;
int maxv[maxn << 2];
int num[maxn];
struct Tree
{
	int u, v, w;
};
Tree e[maxn];
void init()
{
	tot = pos = 0;
	memset(head, -1, sizeof(head));
	memset(son, -1, sizeof(son));
}
void add_edge(int u, int v)
{
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
void dfs_1(int u, int pre, int d)
{
	dep[u] = d, fa[u] = pre, sz[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == pre) continue;
		dfs_1(v, u, d + 1);
		sz[u] += sz[v];
		if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
	}
}
void dfs_2(int u, int tp)
{
	id[u] = pos++;
	top[u] = tp;
	if (son[u] != -1) dfs_2(son[u], tp);
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (fa[u] != v&&v != son[u])
		{
			dfs_2(v, v);
		}
	}
}
void pushup(int s)
{
	maxv[s] = max(maxv[s << 1], maxv[s << 1 | 1]);
}
void build(int l, int r, int s)
{
	if (l == r)
	{
		maxv[s] = num[r];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s);
}
void update(int p, int d, int l, int r, int s)
{
	if (l == r)
	{
		maxv[s] = d;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, d, lson); else
		update(p, d, rson);
	pushup(s);
}
int query(int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr) return maxv[s];
	int m = (l + r) >> 1, ret = 0;
	if (ql <= m) ret = max(ret, query(ql, qr, lson));
	if (qr > m) ret = max(ret, query(ql, qr, rson));
	return ret;
}
int get_max(int u, int v)
{
	int f1 = top[u], f2 = top[v];
	int ret = 0;
	while (f1 != f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(f1, f2);
			swap(u, v);
		}
		ret = max(ret, query(id[f1], id[u], 1, pos - 1, 1));
		u = fa[f1]; f1 = top[u];
	}
	if (u == v) return ret;
	if (dep[u] > dep[v]) swap(u, v);
	ret = max(ret, query(id[son[u]], id[v], 1, pos - 1, 1));
	return ret;
}
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
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			e[i].u = u, e[i].v = v, e[i].w = w;
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs_1(1, 0, 1);
		dfs_2(1, 1);
		for (int i = 1; i < n; i++)
		{
			if (dep[e[i].u] > dep[e[i].v]) swap(e[i].u, e[i].v);
			num[id[e[i].v]] = e[i].w;
		}
		build(1, pos - 1, 1);
		char op[10];
		while (scanf("%s", op) != EOF)
		{
			if (op[0] == 'D') break;
			int u, v;
			scanf("%d%d", &u, &v);
			if (op[0] == 'Q')
			{
				printf("%d\n", get_max(u, v));
			}
			else
			{
				update(id[e[u].v], v, 1, pos - 1, 1);
			}
		}
	}
	return 0;
}
