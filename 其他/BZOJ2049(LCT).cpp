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
typedef long long LL;
int pre[maxn], ch[maxn][2], rev[maxn], n, m;
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
void init()
{
	for (int i = 0; i <= n; i++)
	{
		pre[i] = 0;
		ch[i][0] = ch[i][1] = 0;
		rev[i] = 0;
	}
}
inline bool not_root(int x)
{
	return (pre[x] != 0 && (ch[pre[x]][0] == x || ch[pre[x]][1] == x));
}
void pushdown(int x)
{
	if (!x) return;
	if (rev[x])
	{
		rev[ch[x][0]] ^= 1;
		rev[ch[x][1]] ^= 1;
		rev[x] = 0;
		swap(ch[x][0], ch[x][1]);
	}
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
			int y = pre[x],z=pre[y];
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
}
inline int access(int x)
{
	int v = 0;
	for (; x != 0; x = pre[x])
	{
		Splay(x);
		ch[x][1] = v;
		v = x;
	}
	return v;
}
inline int find_root(int x)
{
	for (x = access(x); pushdown(x), ch[x][0] != 0; x = ch[x][0]);
	//Splay(x);
	return x;
}
inline void evert(int x)
{
	rev[access(x)]^= 1;
	Splay(x);
}
inline void link(int x, int y)
{
	evert(x);
	pre[x] = y;
	access(x);
}
inline void cut(int x, int y)
{
	evert(x);
	access(y);
	Splay(y);
	pushdown(y);
	pre[ch[y][0]] = 0;
	ch[y][0] = 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt","w",stdout);
#endif
	scanf("%d%d", &n, &m);
	//init();
	while (m--)
	{
		char op[15];
		int u, v;
		scanf("%s", op);
		read(u), read(v);
		if (op[0] == 'Q')
		{
			if (find_root(u) == find_root(v))
			{
				puts("Yes");
			}
			else puts("No");
		}
		else if (op[0] == 'C')
		{
			link(u, v);
		}
		else
		{
			cut(u, v);
		}
	}
	return 0;
}
