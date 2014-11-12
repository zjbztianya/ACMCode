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
int id[maxn],revid[maxn];//id[v]表示v与其父亲节点的连边在线段树中的位置
int son[maxn];//重儿子
int pos;
int maxv[maxn << 2],ans[maxn],cnt[maxn],idx[maxn<<2];
vector<int>vec[maxn];
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
	revid[id[u]] = u;
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
void add(int u, int v,int c)
{
	int f1 = top[u], f2 = top[v];
	while (f1!=f2)
	{
		if (dep[f1] < dep[f2])
		{
			swap(u, v);
			swap(f1, f2);
		}
		vec[id[f1]].push_back(c);
		vec[id[u] + 1].push_back(-c);
		u = fa[f1], f1 = top[u];
	}
	if (dep[u] > dep[v]) swap(u, v);
	vec[id[u]].push_back(c);
	vec[id[v] + 1].push_back(-c);
}
void pushup(int s)
{
	if (maxv[s << 1]>=maxv[s << 1 | 1])
	{
		maxv[s] = maxv[s << 1];
		idx[s] = idx[s << 1];
	}
	else
	{
		maxv[s] = maxv[s << 1|1];
		idx[s] = idx[s << 1|1];
	}
}
void update(int p, int op, int l, int r, int s)
{
	if (l == r)
	{
		maxv[s] += op ? 1 : -1;
		idx[s] = r;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m) update(p, op, lson);
	else update(p, op, rson);
	pushup(s);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		if (n==0&&m==0) break;
		init();
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			read(u), read(v);
			add_edge(u, v);
			add_edge(v, u);
		}
		dfs_1(1, 0, 1);
		dfs_2(1, 1);
		memset(maxv, 0, sizeof(maxv));
		for (int i = 1; i <= 100000; i++) vec[i].clear();
		while (m--)
		{
			int u, v, c;
			read(u), read(v), read(c);
			add(u, v,c);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < vec[i].size(); j++)
			{
				int op = vec[i][j] > 0 ? 1 : 0;
				update(abs(vec[i][j]), op,1, 100000, 1);
			}
			ans[revid[i]]= maxv[1]?idx[1]:0;
		}
		for (int i = 1; i <= n; i++) printf("%d\n",ans[i]);
	}
	return 0;
}
