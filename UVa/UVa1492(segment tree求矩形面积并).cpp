
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
#include <cstdlib>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111111
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
struct segment
{
	int l, r, h, s;
	segment(int _l, int _r, int _h, int _s)
	{
		l = _l, r = _r, h = _h, s = _s;
	}
	segment(){}
	bool operator<(const segment &r)const
	{
		return h < r.h;
	}
};
segment seg[maxn];
struct Rectangle
{
	int x1, x2, y1, y2;
	Rectangle(int _x1, int _y1, int _x2, int _y2)
	{
		x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
	}
	Rectangle(){}
};
Rectangle rec[maxn];
int x[maxn],sum[maxn << 2],add[maxn<< 2];
void PushUp(int s, int l, int r)
{
	if (add[s]) sum[s] = x[r + 1] - x[l];
	else if (l == r)
		sum[s] = 0;
	else
		sum[s] = sum[s << 1] + sum[s << 1 | 1];
}
void update(int ql, int qr, int v, int l, int r, int s)
{
	if (ql <= l&&r <= qr) {
		add[s] += v;
		PushUp(s, l, r);
		return;
	}
	int m = (l + r) >> 1;
	if (ql <= m) update(ql, qr, v, lson);
	if (qr>m) update(ql, qr, v, rson);
	PushUp(s, l, r);
}
LL go(int w, int h, int n, int m)
{
	int tot = 0;
	for (int i = 0; i < n; i++)
	{
		seg[tot] = segment(max(1,rec[i].x1-m+1), rec[i].x2 + 1, rec[i].y1, 1);
		x[tot++] = max(1,rec[i].x1-m+1);
		seg[tot] = segment(max(1,rec[i].x1-m+1), rec[i].x2 + 1, rec[i].y2+1, -1);
		x[tot++] = rec[i].x2+1;
	}
	seg[tot] = segment(max(1, w- m+2), w + 1, 1, 1);
	x[tot++] = max(1,w-m+2);
	seg[tot] = segment(max(1, w-m+2),w+1, h+1, -1);
	x[tot++] = w+1;
	sort(x, x + tot);
	sort(seg, seg + tot);
	//printf("##############\n");
	//for (int i = 0; i < tot; i++) printf("%d %d %d %d\n", seg[i].l, seg[i].r, seg[i].h, seg[i].s);
	int cnt = unique(x, x + tot) - x;
	memset(sum, 0, sizeof(sum));
	memset(add, 0, sizeof(add));
	LL ret = 0;
	for (int i = 0; i < tot - 1; i++)
	{
		int l = lower_bound(x, x + cnt, seg[i].l) - x;
		int r = lower_bound(x, x + cnt, seg[i].r) - x;
		update(l, r - 1, seg[i].s,0, cnt - 2, 1);
		ret += (LL)sum[1] * (seg[i + 1].h - seg[i].h);
	}
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	int w, h, n, m;
	while (scanf("%d%d%d%d", &w, &h, &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			rec[i] = Rectangle(x1, y1, x2, y2);
		}
		LL ans = (LL)w*h - go(w,h,n,m);
		for (int i = 0; i < n; i++)
		{
			swap(rec[i].x1, rec[i].y1);
			swap(rec[i].x2, rec[i].y2);
		}
		//for (int i = 0; i < n; i++) printf("%d %d %d %d\n", rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2);
		ans += (LL)w*h - go(h,w,n,m);
		if (m == 1) ans /= 2;
		printf("%I64d\n", ans);
	}
	return 0;
}
