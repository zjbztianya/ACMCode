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
int pos,n;
int maxv[maxn << 2], sum[maxn << 2];
int num[maxn],w[maxn];
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
	fa[u] = pre, dep[u] = d, sz[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == pre) continue;
		dfs_1(v, u, d + 1);
		sz[u] += sz[v];
		if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs_2(int u, int tp)
{
	id[u] = ++pos;
	top[u] = tp;
	if (son[u] != -1) dfs_2(son[u], tp);
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa[u] || v == son[u]) continue;
		dfs_2(v, v);
	}
}
void pushup(int s)
{
	maxv[s] = max(maxv[s << 1], maxv[s << 1 | 1]);
	sum[s] = sum[s << 1] + sum[s << 1 | 1];
}
void build(int l, int r, int s)
{
	if (l == r)
	{
		sum[s] = maxv[s] = w[r];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s);
}
void update(int p, int val, int l, int r, int s)
{
	if (l == r)
	{
		maxv[s] = sum[s] = val;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, val, lson); else
		update(p, val, rson);
	pushup(s);
}
int querymax(int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr) return maxv[s];
	int m = (l + r) >> 1, ret = -INF;
	if (ql <= m) ret = max(ret, querymax(ql, qr, lson));
	if (qr >m) ret = max(ret, querymax(ql, qr, rson));
	return ret;
}
int querysum(int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr) return sum[s];
	int m = (l + r) >> 1, ret =0;
	if (ql <= m) ret += querysum(ql, qr, lson);
	if (qr > m) ret +=querysum(ql, qr, rson);
	return ret;
}
int get_max(int u, int v)
{
	int f1 = top[u], f2 = top[v],ret=-INF;
	while (f1!=f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(u, v);
			swap(f1, f2);
		}
		ret = max(ret, querymax(id[f1], id[u], 1, n, 1));
		u = fa[f1], f1 = top[u];
	}
	if (dep[u] > dep[v])swap(u, v);
	return max(ret, querymax(id[u], id[v], 1, n, 1));
}
int get_sum(int u, int v)
{
	int f1 = top[u], f2 = top[v], ret = 0;
	while (f1!=f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(u, v);
			swap(f1, f2);
		}
		ret += querysum(id[f1], id[u], 1, n, 1);
		u = fa[f1], f1 = top[u];
	}
	if (dep[u] > dep[v]) swap(u, v);
	return ret + querysum(id[u], id[v], 1, n, 1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
		scanf("%d", &n);
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
		dfs_1(1, 0, 1);
		dfs_2(1, 1);
		for (int i = 1; i <= n; i++)
		{
			w[id[i]] = num[i];
		}
		build(1, n, 1);
		int Q;
		scanf("%d", &Q);
		while (Q--)
		{
			char op[10];
			int u, v;
			scanf("%s%d%d",op,&u, &v);
			if (op[1] == 'M')
			{
				printf("%d\n", get_max(u, v));
			}
			else if (op[1] == 'S')
			{
				printf("%d\n", get_sum(u, v));
			}
			else
			{
				update(id[u], v, 1, n, 1);
			}
		}

	return 0;
}
