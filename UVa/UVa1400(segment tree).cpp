
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
#define  maxn 555555
#define  lson l,m,s<<1
#define  rson m+1,r,s<<1|1
typedef long long LL;
LL sum[maxn << 2], presum[maxn << 2], sucsum[maxn << 2], maxsum[maxn << 2];
pair<int, int>pos[maxn << 2],prepos[maxn<<2],sucpos[maxn<<2];
struct  node
{
	LL sum, presum, sucsum, maxsum;
	pair<int, int>pos, prepos, sucpos;
	node(LL _sum, LL _presum, LL _sucsum, LL _maxsum, pair<int, int>_pos, pair<int, int>_prepos, pair<int, int>_sucpos)
	{
		sum=_sum,presum=_presum, sucsum=_sucsum, maxsum=_maxsum;
		pos = _pos, prepos = _prepos, sucpos = _sucpos;
	}
	node(){}
};
void pushup(int s,int l,int r)
{
	if (maxsum[s << 1] >=maxsum[s << 1 | 1])
	{
		pos[s] = pos[s << 1];
		maxsum[s] = maxsum[s << 1];
	}
	else
	{
		pos[s] = pos[s << 1|1];
		maxsum[s] = maxsum[s << 1|1];
	}
	if (maxsum[s] < sucsum[s << 1] + presum[s << 1 | 1] || ((maxsum[s] == sucsum[s << 1] + presum[s << 1 | 1]) && (sucpos[s << 1].first<pos[s].first || (sucpos[s << 1].first==pos[s].first&&prepos[s<<1|1].second<pos[s].second))))
	{
		maxsum[s] = sucsum[s << 1] + presum[s << 1 | 1];
		pos[s].first = sucpos[s << 1].first;
		pos[s].second = prepos[s << 1 | 1].second;
	}
	sum[s] = sum[s << 1] + sum[s << 1 | 1];
	presum[s] = presum[s << 1], prepos[s] = prepos[s << 1];
	sucsum[s] = sucsum[s << 1 | 1], sucpos[s] = sucpos[s << 1 | 1];
	if (sum[s << 1]+presum[s<<1|1]>presum[s])
	{
		presum[s] = sum[s << 1] + presum[s << 1 | 1];
		prepos[s].first = prepos[s << 1].first;
		prepos[s].second = prepos[s << 1 | 1].second;
	}
	if (sum[s << 1 | 1] +sucsum[s << 1]>=sucsum[s])
	{
		sucsum[s] = sum[s << 1 | 1] + sucsum[s << 1];
		sucpos[s].first = sucpos[s << 1].first;
		sucpos[s].second = sucpos[s << 1 | 1].second;
	}
}
void build(int l, int r, int s)
{
	if (l == r)
	{
		scanf("%I64d", &sum[s]);
		presum[s] = sucsum[s] = maxsum[s] = sum[s];
		pos[s].first = pos[s].second = r;
		prepos[s].first = prepos[s].second = r;
		sucpos[s].first = sucpos[s].second = r;
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s,l,r);
}
node  query(int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr)
	{
		node ss = node(sum[s], presum[s], sucsum[s], maxsum[s],pos[s], prepos[s], sucpos[s]);
		return ss;
	}
	int m = (l + r) >> 1;
	node ret;
	if (qr <= m) ret = query(ql, qr, lson);
	else if (ql > m)
		ret =  query(ql, qr, rson);
	else
	{
		node ls = query(ql, qr, lson);
		node rs = query(ql, qr, rson);
		if (ls.maxsum>= rs.maxsum)
		{
			ret = ls;
		}
		else
		{
			ret = rs;
		}
		if (ret.maxsum< ls.sucsum + rs.presum || (ret.maxsum == ls.sucsum + rs.presum && (ls.sucpos.first<ret.pos.first || (ls.sucpos.first==ret.pos.first&&rs.prepos.second<ret.pos.second))))
		{
			ret.maxsum = ls.sucsum+rs.presum;
			ret.pos.first = ls.sucpos.first;
			ret.pos.second = rs.prepos.second;
		}
		ret.sum = ls.sum + rs.sum;
		ret.presum =ls.presum, ret.prepos = ls.prepos;
		ret.sucsum =rs.sucsum, ret.sucpos = rs.sucpos;
		if (ls.sum+rs.presum>ret.presum)
		{
			ret.presum = ls.sum +rs.presum;
			ret.prepos.first =ls.prepos.first;
			ret.prepos.second = rs.prepos.second;
		}
		if (rs.sum+ls.sucsum>=ret.sucsum)
		{
			ret.sucsum = rs.sum + ls.sucsum;
			ret.sucpos.first = ls.sucpos.first;
			ret.sucpos.second = rs.sucpos.second;
		}
	}
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int n, m,kase=0;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		printf("Case %d:\n", ++kase);
		build(1, n, 1);
		while (m--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			node ans=query(l, r, 1, n, 1);
			printf("%d %d\n", ans.pos.first, ans.pos.second);
		}
	}
	return 0;
}
