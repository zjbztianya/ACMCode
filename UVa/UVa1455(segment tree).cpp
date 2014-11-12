
#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。

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
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 2222222
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
struct node
{
	int l, r,fa,cnt;
};
node st[maxn];
struct  ND
{
	int sum, cnt;
};
int sum[maxn << 2], ct[maxn],cnt[maxn<<2],addf[maxn<<2],adds[maxn<<2];
int find(int x)
{
	return x == st[x].fa ? x : st[x].fa = find(st[x].fa);
}
void pushup(int s)
{
	sum[s] = sum[s << 1] + sum[s << 1 | 1];
	cnt[s] = cnt[s << 1] + cnt[s << 1 | 1];
}
void pushdown(int s,int l,int r)
{
	int m = (l + r) >> 1;
	if (adds[s]!=0)
	{
		cnt[s << 1] += (m-l+1)*adds[s];
		cnt[s << 1 | 1] += (r-m)*adds[s];
		adds[s<<1] += adds[s];
		adds[s<<1|1] += adds[s];
		adds[s] = 0;
	}
	if (addf[s] != 0)
	{
		sum[s << 1] +=(m-l+1)*addf[s];
		sum[s << 1 | 1] += (r-m)*addf[s];
		addf[s << 1] += addf[s];
		addf[s << 1 | 1] += addf[s];
		addf[s] = 0;
	}
}
void build(int l, int r, int s)
{
	addf[s] = 0,adds[s]=0;
	if (l == r)
	{
		cnt[s]=sum[s] = ct[r];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s);
}
void update(int ql, int qr, int l, int r, int s, int op,int t)
{
	if (ql <= l&&r <= qr)
	{
		if (op == 1)
		{
			sum[s]-=(r-l+1);
			cnt[s] -= (r-l+1)*t;
			adds[s] -= t;
			addf[s]--;

		}
		else
		{
			sum[s]+=(r-l+1);
			cnt[s] += (r-l+1)*t;
			adds[s] += t;
			addf[s]++;
		}
		return;
	}
	pushdown(s,l,r);
	int m = (l + r) >> 1;
	if (ql <= m) update(ql, qr, lson, op,t);
	if (qr > m) update(ql, qr, rson, op,t);
	pushup(s);
}
ND query(int l, int r, int s, int p)
{
	if (l == r)
	{
		ND ss;
		ss.sum = sum[s], ss.cnt = cnt[s];
		return ss;
	}
	pushdown(s,l,r);
	int m = (l + r) >> 1;
	if (p <= m) return query(lson, p);
	else return query(rson, p);
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
		int r = 0;
		memset(ct, 0, sizeof(ct));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			st[i].fa = i;
			st[i].l = st[i].r = 2 * y;
			st[i].cnt = 1;
			ct[2*y] ++;
			r = max(r, 2 * y);
		}
		build(0, r, 1);
		int m;
		scanf("%d", &m);
		while (m--)
		{
			char op[10];
			scanf("%s", op);
			if (op[0] == 'r')
			{
				int u,v;
				scanf("%d%d", &u, &v);
				u = find(u), v = find(v);
				if (u != v)
				{
					update(st[u].l, st[u].r,0, r, 1,1,st[u].cnt);
					update(st[v].l, st[v].r,0, r, 1,1,st[v].cnt);
					st[u].fa = v;
					st[v].cnt += st[u].cnt;
					st[v].l = min(st[v].l, st[u].l);
					st[v].r = max(st[v].r, st[u].r);
					update(st[v].l, st[v].r,0, r, 1, 2,st[v].cnt);
				}
			}
			else
			{
				double x;
				scanf("%lf", &x);
				x *= 2;
				int L = x;
				ND ans; 
				if (L<0 || L>r)
				{
					ans.sum = 0, ans.cnt = 0;
				}else ans=query(0, r, 1, L);
				printf("%d %d\n",ans.sum,ans.cnt);
			}
		}
	}
	return 0;
}
