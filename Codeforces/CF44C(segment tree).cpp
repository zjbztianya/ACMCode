
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
using namespace std;
#define  maxn 100005
#define  INF 0x3f3f3f3f
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
LL sum[maxn << 2], add[maxn << 2];
int col[maxn << 2];
void pushup(int s)
{
	sum[s] = sum[s << 1] + sum[s << 1 | 1];
	col[s] = col[s << 1] == col[s << 1 | 1] ? col[s << 1] : 0;
}
void pushdown(int s, int m)
{
	if (col[s]) col[s << 1] = col[s << 1 | 1] = col[s];
	if (add[s])
	{
		add[s << 1] += add[s];
		add[s << 1 | 1] += add[s];
		sum[s << 1] += (LL)(m - (m >> 1))*add[s];
		sum[s << 1 | 1] += (LL)(m >> 1)*add[s];
		add[s] = 0;
	}
}
void build(int l, int r, int s)
{
	add[s] = 0;
	if (l == r)
	{
		col[s] = r;
		sum[s] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s);
}
void update(int ql, int qr, int x, int l, int r, int s)
{
	if (ql <= l&&r <= qr)
	{
		if (col[s])
		{
			sum[s] += (LL)(r - l + 1)*(abs(x - col[s]));
			add[s] += abs(x - col[s]);
			col[s] = x;
			return;
		}
	}
	pushdown(s, r - l + 1);
	int m = (l + r) >> 1;
	if (ql <= m) update(ql, qr, x, lson);
	if (qr > m) update(ql, qr, x, rson);
	pushup(s);
}
LL query(int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr) return sum[s];
	pushdown(s, r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if (ql <= m) ret += query(ql, qr, lson);
	if (qr > m)ret += query(ql, qr, rson);
	return ret;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	while (m--)
	{
		int l, r, x, op;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d%d%d", &l, &r, &x);
			update(l, r, x, 1, n, 1);
		}
		else
		{
			scanf("%d%d", &l, &r);
			printf("%I64d\n", query(l, r, 1, n, 1));
		}
	}
	return 0;
}

