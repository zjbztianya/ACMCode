
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
#define  maxn 66666
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
int n, k;
int sum[maxn << 2][15],x[maxn],add[maxn<<2];
struct segment 
{
	int  l, r, h;
	int dr;
	segment(int _l, int _r, int _h,int _dr)
	{
		l = _l, r = _r, h = _h, dr = _dr;
	}
	segment(){}
	bool operator<(const segment &r)const
	{
		return h < r.h;
	}
};
segment seg[maxn];
void pushup(int l, int r, int s)
{
	if (add[s] >= k)
	{
		memset(sum[s], 0, sizeof(sum[s]));
		sum[s][k] = x[r + 1] - x[l];
	}
	else if (l == r)
	{
		memset(sum[s], 0, sizeof(sum[s]));
		sum[s][add[s]] = x[r + 1] - x[l];
	}
	else
	{
		memset(sum[s], 0, sizeof(sum[s]));
		for (int i = add[s]; i <= k; i++)
			sum[s][i] = sum[s << 1][i - add[s]] + sum[s << 1 | 1][i - add[s]];
		for (int i = k - add[s] + 1; i <= k; i++)
			sum[s][k] += sum[s << 1][i] + sum[s << 1 | 1][i];
	}
}
void build(int l, int r, int s)
{
	add[s] = 0;
	memset(sum[s], 0, sizeof(sum[s]));
	sum[s][0] = x[r + 1] - x[l];
	//if(s==1) printf("%d\n", sum[s][0]);
	if (l == r) return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}
void update(int ql, int qr, int v, int l, int r, int s)
{
	if (ql <= l&&r <= qr)
	{
		add[s] += v;
		pushup(l, r, s);
		return;
	}
	int m = (l + r) >> 1;
	if (ql <= m) update(ql, qr, v, lson);
	if (qr > m) update(ql, qr, v, rson);
	pushup(l, r, s);
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
		scanf("%d%d", &n,&k);
		int tot = 0,cnt=0;
		for (int i = 0; i < n; i++)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x2++, y2++;
			seg[cnt] = segment(x1, x2, y1,1);
			x[cnt++] = x1;
			seg[cnt] = segment(x1, x2, y2,-1);
			x[cnt++] = x2;
		}
		sort(x, x + cnt);
		sort(seg, seg + cnt);
		tot = unique(x, x + cnt) - x;
		build(0, tot - 2, 1);
		LL ans = 0;
		for (int i = 0; i < cnt-1; i++)
		{
			int l = lower_bound(x, x + tot , seg[i].l) - x;
			int r = lower_bound(x, x + tot , seg[i].r) - x;
			update(l, r - 1, seg[i].dr, 0, tot - 2, 1);
			ans += (LL)sum[1][k] * (seg[i + 1].h - seg[i].h);
		}
		printf("Case %d: %I64d\n",++kase,ans);
	}
	return 0;
}
