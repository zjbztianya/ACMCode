#include "stdafx.h"
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
#define lson ch[x][0]
#define rson ch[x][1]
typedef long long LL;
int pre[maxn], ch[maxn][2], rev[maxn],add[maxn],n, m;
int sz[maxn], val[maxn], maxv[maxn][2], setv[maxn],cnt[maxn][2];
void init()
{
	for (int i = 1; i <= n; i++)
	{
		pre[i] =ch[i][0] = ch[i][1] = 0;
		rev[i] =add[i] = cnt[i][1]=0;
		sz[i]=cnt[i][0] = 1;
		maxv[i][1] =setv[i] = -INF;
	}
}
inline bool not_root(int x)
{
	return (pre[x] != 0 && (ch[pre[x]][0] == x || ch[pre[x]][1] == x));
}
void Set(int x,int d)
{
	if (!x) return;
	val[x] = maxv[x][0] = d;
	add[x] = 0;
	setv[x] = d;
	maxv[x][1] = -INF;
	cnt[x][0] = sz[x];
	cnt[x][1] = 0;
}
void Reverse(int x)
{
	if (!x) return;
	if(lson) rev[lson] ^= 1;
	if(rson) rev[rson] ^= 1;
	swap(lson, rson);
}
void Add(int x,int d)
{
	if (!x) return;
	val[x] += d;
	maxv[x][0] += d;
	add[x] += d;
	if (maxv[x][1] != -INF) maxv[x][1] += d;
}
void pushdown(int x)
{
	if (!x) return;
	if (rev[x])
	{
		Reverse(x);
		rev[x] = 0;
	}
	if (setv[x] != -INF)
	{
		Set(lson,setv[x]);
		Set(rson,setv[x]);
		setv[x] = -INF;
	}
	if (add[x])
	{
		Add(lson,add[x]);
		Add(rson,add[x]);
		add[x] = 0;
	}
}
void pushup(int x)
{
	sz[x] = sz[lson] + sz[rson] + 1;
	int seq[6],t=1;
	seq[0] = val[x];
	if (lson)
	{
		seq[t++] = maxv[lson][0];
		seq[t++] = maxv[lson][1];
	}
	if (rson)
	{
		seq[t++] = maxv[rson][0];
		seq[t++] = maxv[rson][1];
	}
	sort(seq, seq + t);
	int tot = unique(seq, seq + t) - seq;
	maxv[x][0] = seq[tot - 1];
	if (tot - 2 >= 0) maxv[x][1] = seq[tot - 2]; else maxv[x][1] = -INF;
	cnt[x][0] = cnt[x][1] = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (maxv[ch[x][i]][j] == maxv[x][0]) cnt[x][0] += cnt[ch[x][i]][j];
			if (maxv[ch[x][i]][j] == maxv[x][1]) cnt[x][1] += cnt[ch[x][i]][j];
		}
	}
	if (val[x] == maxv[x][0]) cnt[x][0]++;
	if (val[x] == maxv[x][1]) cnt[x][1]++;
}
void  Rotate(int x, int f)
{
	int y = pre[x];
	ch[y][!f] = ch[x][f];
	if (ch[x][f]) pre[ch[x][f]] = y;
	pre[x] = pre[y];
	if (not_root(y)) ch[pre[y]][ch[pre[y]][1] == y] = x;
	ch[x][f] = y;
	pre[y] = x;
	pushup(y);
}
void Splay(int x)
{
	pushdown(x);
	while (not_root(x))
	{
		if (!not_root(pre[x]))
		{
			pushdown(pre[x]), pushdown(x);
			Rotate(x, ch[pre[x]][0] == x);
		}
		else
		{
			int y = pre[x], z = pre[y];
			pushdown(z), pushdown(y), pushdown(x);
			int f = (ch[z][0] == y);
			if (ch[y][f] == x)
			{
				Rotate(x, !f), Rotate(x, f);
			}
			else
			{
				Rotate(y, f), Rotate(x, f);
			}
		}
	}
	pushup(x);
}
int access(int x)
{
	int v = 0;
	for (; x != 0; x =pre[x])
	{
		Splay(x);
		ch[x][1] = v;
		pushup(v = x);
	}
	return v;
}
int find_root(int x)
{
	for (x = access(x); pushdown(x), ch[x][0] != 0; x = ch[x][0]);
	Splay(x);
	return x;
}
void evert(int x)
{
	rev[access(x)] ^= 1;
	Splay(x);
}
void link(int x, int y)
{
	if (find_root(x) == find_root(y)) return;
	evert(x);
	pre[x] = y;
	access(x);
}
void cut(int x, int y)
{
	if (x == y || find_root(x) != find_root(y)) return;
	evert(x);
	access(y);
	Splay(y);
	pre[ch[y][0]] = 0;
	ch[y][0] = 0;
	pushup(y);
}
void change(int x, int y, int v)
{
	if (find_root(x) != find_root(y)) return;
	evert(x);
	access(y);
	Splay(y);
	setv[y] = v;
	add[y] = 0;
	maxv[y][0]=val[y]=v;
	cnt[y][0] = sz[y];
	cnt[y][1] = 0;
	maxv[y][1] = -INF;
}
void update(int x, int y, int d)
{
	if (find_root(x) != find_root(y)) return;
	evert(x);
	access(y);
	Splay(y);
	add[y] += d;
	maxv[y][0] += d;
	val[y] += d;
	if (maxv[y][1] != -INF) maxv[y][1] += d;
}
void query(int x, int y)
{
	if (find_root(x) != find_root(y)) return;
	evert(x);
	access(y);
	Splay(y);
	if (maxv[y][1]==-INF)
	{
		puts("ALL SAME");
	}
	else
	{
		printf("%d %d\n", maxv[y][1],cnt[y][1]);
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
		read(n), read(m);
		init();
		for (int i = 1; i <= n; i++)
		{
			read(val[i]);
			maxv[i][0] = val[i];
		}
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			read(u), read(v);
			link(u, v);
		}
		printf("Case #%d:\n", ++kase);
		while (m--)
		{
			int op, x, y, a, b;
			read(op);
			if (op == 1)
			{
				read(x), read(y), read(a), read(b);
				cut(x, y), link(a, b);
			}
			else if (op == 2)
			{
				read(a), read(b), read(x);
				change(a, b, x);
			}
			else if (op == 3)
			{
				read(a), read(b), read(x);
				update(a, b, x);
			}
			else
			{
				read(a), read(b);
				query(a, b);
			}
		}
	}
	return 0;
}