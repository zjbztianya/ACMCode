#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
#pragma warning(disable : 4786)
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int c[maxn],w[maxn];
void init()
{
	tot = pos = 0;
	memset(head, -1, sizeof(head));
	memset(son, -1, sizeof(son));
	memset(c, 0, sizeof(c));
	memset(w, 0, sizeof(w));
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
		if (v ==pre) continue;
		dfs_1(v, u, d + 1);
		sz[u] += sz[v];
		if (son[u] == -1 || sz[v] > sz[son[u]]) son[u] = v;
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
		if (v == son[u] || v == fa[u]) continue;
		dfs_2(v, v);
	}
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
int lowbit(int x)
{
	return x&-x;
}
void add(int *c, int x,int d)
{
	while (x<=n)
	{
		c[x] += d;
		x += lowbit(x);
	}
}
int query(int *c, int x)
{
	int ret = 0;
	while (x>0)
	{
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}
void add1(int u, int v,int k)
{
	int f1 = top[u], f2 = top[v];
	while (f1!=f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(u, v);
			swap(f1, f2);
		}
		add(c, id[f1], k);
		add(c, id[u] + 1, -k);
		u = fa[f1], f1 = top[u];
	}
	if (dep[u] > dep[v]) swap(u, v);
	add(c, id[u], k);
	add(c, id[v] + 1, -k);
}
void add2(int u, int v,int k)
{
	int f1 = top[u], f2 = top[v];
	while (f1!=f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(u, v);
			swap(f1, f2);
		}
		add(w, id[f1], k);
		add(w,id[u] + 1, -k);
		u = fa[f1], f1 = top[u];
	}
	if (u == v) return;
	if (dep[u] > dep[v]) swap(u, v);
	add(w, id[son[u]], k);
	add(w, id[v] + 1, -k);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	int T,kase=0;
	scanf("%d", &T);
	while (T--)
	{
		init();
		int m;
		read(n),read(m);
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			read(u), read(v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs_1(1, 0, 1);
		dfs_2(1, 1);
		while (m--)
		{
			char op[10];
			int u, v, k;
			scanf("%s", op);
			read(u), read(v), read(k);
			if (op[3] == '1')
			{
				add1(u, v,k);
			}
			else
			{
				add2(u, v,k);
			}
		}
		printf("Case #%d:\n", ++kase);
		for (int i = 1; i <n; i++)
		{
			printf("%d ", query(c, id[i]));
		}
		printf("%d\n", query(c, id[n]));
		if (n == 1) puts("");
		else
		{
			for (int i = 2; i < n; i++)
			{
				printf("%d ", query(w, id[i]));
			}
			printf("%d\n", query(w, id[n]));
		}
	}
	return 0;
}
