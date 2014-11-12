
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
#define  maxn 111111
#define  lson l,m,s<<1
#define  rson m+1,r,s<<1|1
typedef long long LL;
int sum[22][maxn << 2], addv[22][maxn << 2], setv[22][maxn << 2];
int maxv[22][maxn << 2], minv[22][maxn << 2];
struct node
{
	int maxv, minv,sumv;
	node(int _sumv, int _minv, int _maxv)
	{
		maxv = _maxv;
		minv = _minv;
		sumv = _sumv;
	}
	node(){}
};
void pushup(int i,int s)
{
	sum[i][s] = sum[i][s << 1] + sum[i][s << 1 | 1];
	minv[i][s] = min(minv[i][s << 1], minv[i][s << 1 | 1]);
	maxv[i][s] = max(maxv[i][s << 1], maxv[i][s << 1 | 1]);
}
void pushdown(int i,int l,int r,int s)
{
	int m = (l + r) >> 1;
	if (setv[i][s] != -1)
	{
		setv[i][s << 1] = setv[i][s << 1 | 1] = setv[i][s];
		sum[i][s << 1] = (m - l + 1)*setv[i][s];
		sum[i][s << 1 | 1] = (r - m)*setv[i][s];
		addv[i][s << 1] = addv[i][s << 1 | 1] = 0;
		minv[i][s << 1] = minv[i][s << 1 | 1] = setv[i][s];
		maxv[i][s << 1] = maxv[i][s << 1 | 1] = setv[i][s];
		setv[i][s] = -1;
	}
	if (addv[i][s])
	{
		addv[i][s << 1] += addv[i][s];
		addv[i][s << 1 | 1] += addv[i][s];
		sum[i][s << 1] += (m - l + 1)*addv[i][s];
		sum[i][s << 1 | 1] += (r - m)*addv[i][s];
		minv[i][s << 1] += addv[i][s];
		minv[i][s << 1 | 1] += addv[i][s];
		maxv[i][s << 1] += addv[i][s];
		maxv[i][s << 1 | 1] += addv[i][s];
		addv[i][s] =0;
	}
}
void update(int i, int ql, int qr, int l, int r, int s, int v, int op)
{
	if (ql <= l&&r <= qr)
	{
		if (op == 2)
		{
			sum[i][s] = (r - l + 1)*v;
			addv[i][s] = 0;
			setv[i][s] = v;
			maxv[i][s] = minv[i][s] = v;
		}
		if (op == 1)
		{
			sum[i][s] += (r - l + 1)*v;
			addv[i][s] += v;
			maxv[i][s] += v;
			minv[i][s] += v;
		}
		return;
	}
	pushdown(i,l,r,s);
	int m = (l + r) >> 1;
	if (ql <= m) update(i, ql, qr, lson, v, op);
	if (qr > m) update(i, ql, qr, rson, v, op);
	pushup(i,s);
}
node query(int i, int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr)
	{
		node ss = node(sum[i][s],minv[i][s],maxv[i][s]);
		return ss;
	}
	pushdown(i, l, r, s);
	int m = (l + r) >> 1;
	node ret,ll,rr;
	ll = node(0, INF, 0);
	rr = node(0, INF, 0);
	if (ql <= m) ll = query(i, ql, qr, lson);
	if (qr > m) rr = query(i, ql, qr, rson);
	ret.minv = min(ll.minv, rr.minv);
	ret.maxv = max(ll.maxv, rr.maxv);
	ret.sumv = ll.sumv + rr.sumv;
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int r, c, m;
	while (scanf("%d%d%d",&r,&c,&m)!=EOF)
	{
		memset(sum, 0, sizeof(sum));
		memset(addv, 0, sizeof(addv));
		memset(setv, -1, sizeof(setv));
		memset(maxv, 0, sizeof(maxv));
		memset(minv, 0, sizeof(minv));
		while (m--)
		{
			int op, x1, x2, y1, y2,v;
			scanf("%d%d%d%d%d", &op, &x1, &y1, &x2, &y2);
			if (op == 1)
			{
				scanf("%d", &v);
				for (int i = x1; i <= x2; i++) update(i,y1, y2, 1, c, 1,v,1);
			}
			else if (op == 2)
			{
				scanf("%d", &v);
				for (int i = x1; i <= x2; i++) update(i,y1, y2, 1, c, 1,v,2);
			}
			else
			{
				node ans = node(0,INF,0);
				for (int i = x1; i <= x2; i++)
				{
					node t = query(i, y1, y2, 1, c, 1);
					ans.sumv += t.sumv;
					ans.minv = min(ans.minv, t.minv);
					ans.maxv = max(ans.maxv, t.maxv);
				}
				printf("%d %d %d\n", ans.sumv, ans.minv, ans.maxv);
			}
		}
	}
	return 0;
}
