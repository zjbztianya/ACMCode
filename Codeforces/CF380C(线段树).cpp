
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
using namespace std;
#define  maxn 1111111
#define  INF 0x3f3f3f3f
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
int a[maxn << 2], b[maxn << 2], c[maxn << 2];
char str[maxn];
int ls;
void pushup(int s,int l,int r)
{
	int t = min(b[s << 1], c[s << 1 | 1]);
	a[s] = a[s << 1] + a[s << 1 | 1] + t;
	b[s] = b[s << 1] + b[s << 1 | 1] - t;
	c[s] = c[s << 1] + c[s << 1 | 1] - t;
}
void build(int l, int r, int s)
{
	if (l == r)
	{
		a[s] = 0;
		if (str[l] == '(')
		{
			b[s] = 1;
			c[s] = 0;
		}
		else
		{
			b[s] = 0;
			c[s] = 1;
		}
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	pushup(s,l,r);
}
int query(int ql,int qr,int l, int r, int s)
{
	if (ql <= l&&r <= qr)
	{
		int len = min(ls, c[s]);
		ls += b[s] - len;
		return a[s]+len;
	}
	int m = (l + r) >> 1, ret = 0;
	if (ql <= m) ret += query(ql, qr, lson);
	if (qr > m) ret += query(ql, qr, rson);
	return ret;
}
int main()
{
	scanf("%s", str+1);
	int m,n;
	n = strlen(str+1);
	build(1, n, 1);
	scanf("%d", &m);
	while (m--)
	{
		int l, r;
		ls = 0;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r,1,n,1)*2);
	}
	return 0;
}

