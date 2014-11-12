
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
#define  maxn 1111111
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
int sum[maxn << 2], rev[maxn << 2], setv[maxn << 2];
char str[maxn];
int num[maxn];
void pushup(int s)
{
	sum[s] = sum[s << 1] + sum[s << 1 | 1];
}
void pushdown(int s,int l,int r)
{
	int m = (l + r) >> 1;
	if (setv[s] != -1)
	{
		setv[s << 1] = setv[s << 1 | 1] = setv[s];
		sum[s << 1] = (m - l + 1)*setv[s];
		sum[s << 1 | 1] = (r - m)*setv[s];
		setv[s] = -1;
		rev[s << 1] = rev[s << 1 | 1] = 0;
	}
	if (rev[s])
	{
		rev[s << 1] ^= 1;
		rev[s << 1 | 1] ^=1;
		sum[s << 1] = (m - l + 1) - sum[s << 1];
		sum[s << 1 | 1] = r - m - sum[s << 1 | 1];
		rev[s] ^=1;
	}
}
void build(int l, int r, int s)
{
	rev[s] = 0; setv[s] = -1;
	if (l == r)
	{
		sum[s] = num[r];
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s);
}
void update(int ql, int qr, int l, int r, int s, int op)
{
	if (ql <= l&&r <= qr)
	{
		if (op == 1)
		{
			sum[s] = (r - l + 1);
			setv[s] = 1;
			rev[s] = 0;
		}
		else if (op == 2)
		{
			sum[s] = 0;
			setv[s] = 0;
			rev[s] = 0;
		}
		else
		{
			sum[s] = r - l + 1 - sum[s];
			rev[s] ^= 1;
		}
		return;
	}
	pushdown(s,l,r);
	int m = (l + r) >> 1;
	if (ql <= m) update(ql, qr, lson, op);
	if (qr > m) update(ql, qr, rson, op);
	pushup(s);
}
int query(int ql, int qr, int l, int r, int s)
{
	if (ql <= l&&r <= qr) return sum[s];
	pushdown(s,l,r);
	int m = (l + r) >> 1,ret=0;
	if (ql <= m) ret += query(ql, qr, lson);
	if (qr > m) ret += query(ql, qr, rson);
	return ret;

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
		printf("Case %d:\n", ++kase);
		int n, cnt;
		scanf("%d", &cnt);
		n = 0;
		while (cnt--)
		{
			int k;
			scanf("%d", &k);
			scanf("%s", str);
			int len = strlen(str);
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < len; j++) num[n++] = str[j] - '0';
			}
		}
		build(0, n-1, 1);
		int m,q=0;
		scanf("%d", &m);
		while (m--)
		{
			char op[10];
			int a, b;
			scanf("%s%d%d", op, &a, &b);
			if (op[0] == 'S') printf("Q%d: %d\n", ++q,query(a, b, 0, n-1, 1));
			if (op[0] == 'F') update(a, b, 0, n-1, 1, 1);
			if (op[0] == 'E') update(a, b, 0, n-1, 1, 2);
			if (op[0] == 'I') update(a, b, 0, n-1, 1, 3);
		}
	}
	return 0;
}
