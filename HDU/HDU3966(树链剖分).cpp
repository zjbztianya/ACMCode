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
int c[maxn];
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
int lowbit(int x)
{
	return x&-x;
}
void add(int x, int val)
{
	while (x<=n)
	{
		c[x] += val;
		x += lowbit(x);
	}
}
int query(int x)
{
	int ret = 0;
	while (x>0)
	{
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}
void change(int u, int v,int k)
{
	int f1 = top[u], f2 = top[v],ret=-INF;
	while (f1!=f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(u, v);
			swap(f1, f2);
		}
		add(id[f1], k);
		add(id[u] + 1, -k);
		u = fa[f1], f1 = top[u];
	}
	if (dep[u] > dep[v])swap(u, v);
	add(id[u], k);
	add(id[v] + 1, -k);
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
	int m, Q;
	while (scanf("%d%d%d", &n, &m, &Q) != EOF)
	{
		init();
		for (int i = 1; i <= n; i++) read(num[i]);
		for (int i = 1; i <=m; i++)
		{
			int u, v;
			read(u), read(v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs_1(1, 0, 1);
		dfs_2(1, 1);
		memset(c, 0, sizeof(c));
		while (Q--)
		{
			char op[10];
			int u,v,k;
			scanf("%s", op);
			if (op[0] == 'I')
			{
				read(u), read(v), read(k);
				change(u, v, k);
			}
			else if (op[0] == 'D')
			{
				read(u), read(v), read(k);
				change(u, v, -k);
			}
			else
			{
				read(u);
				printf("%d\n",num[u]+query(id[u]));
			}
		}
	}
	return 0;
}
