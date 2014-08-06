
#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 333333
typedef long long LL;
int num[maxn];
struct SplayTree
{
	int ch[maxn][2];
	int pre[maxn];
	int sz[maxn];
	int rev[maxn];
	int add[maxn];
	int minv[maxn];
	int val[maxn];
	int rt, tot;
	void  Rotate(int x, int f)
	{
		int y = pre[x];
		pushdown(y);
		pushdown(x);
		ch[y][!f] = ch[x][f];
		if (ch[x][f]) pre[ch[x][f]] = y;
		pre[x] = pre[y];
		if (pre[y]) ch[pre[y]][ch[pre[y]][1] == y] = x;
		ch[x][f] = y;
		pre[y] = x;
		pushup(y);
	}
	void Splay(int x, int goal)
	{
		pushdown(x);
		while (pre[x] != goal)
		{
			if (pre[pre[x]] == goal)
			{
				Rotate(x, ch[pre[x]][0] == x);
			}
			else
			{
				int y = pre[x], z = pre[y];
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
		if (goal == 0) rt = x;
	}
	int  get_kth(int k)
	{
		int x = rt;
		pushdown(x);
		for (;;)
		{
			int tmp = sz[ch[x][0]];
			if (tmp + 1 == k) break;
			if (k <= tmp) x = ch[x][0];
			else
			{
				k -= (tmp + 1);
				x = ch[x][1];
			}
			pushdown(x);
		}
		return x;
	}
	void RotateTo(int k, int goal)
	{
		int x = get_kth(k);
		Splay(x, goal);
	}
	void  newnode(int &x, int f, int k, int c)
	{
		x = k;
		ch[x][0] = ch[x][1] = rev[x] = add[x] = 0;
		pre[x] = f;
		sz[x] = 1;
		val[x] = minv[x] = c;
	}
	void  pushup(int x)
	{
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
		minv[x] = min(min(minv[ch[x][0]], val[x]), minv[ch[x][1]]);
	}
	void  go_rev(int x)
	{
		if (x)
		{
			swap(ch[x][0], ch[x][1]);
			rev[x] ^= 1;
		}
	}
	void pushdown(int x)
	{
		if (rev[x])
		{
			go_rev(ch[x][0]);
			go_rev(ch[x][1]);
			rev[x] ^= 1;
		}
		if (add[x])
		{
			if (ch[x][0]) {
				minv[ch[x][0]] += add[x];
				val[ch[x][0]] += add[x];
				add[ch[x][0]] += add[x];
			}
			if (ch[x][1])
			{
				minv[ch[x][1]] += add[x];
				val[ch[x][1]] += add[x];
				add[ch[x][1]] += add[x];
			}
			add[x] = 0;
		}
	}
	void  makeTree(int &x, int l, int r, int f) {
		if (l > r) return;
		int m = (l + r) >> 1;
		newnode(x, f, m, num[m]);
		makeTree(ch[x][0], l, m - 1, x);
		makeTree(ch[x][1], m + 1, r, x);
		pushup(x);
	}
	void init(int n)
	{
		ch[0][0] = ch[0][1] = sz[0] = pre[0] = rev[0] = 0;
		minv[0] = val[0] = INF;
		rt = 0;
		newnode(rt, 0, n + 1, INF);
		newnode(ch[rt][1], rt, n + 2, INF);
		makeTree(ch[ch[rt][1]][0], 1, n, ch[rt][1]);
		tot = n + 2;
		pushup(ch[rt][1]);
		pushup(rt);
	}
	void  REVERSE(int x, int y)
	{
		RotateTo(x, 0);
		RotateTo(y + 2, rt);
		go_rev(ch[ch[rt][1]][0]);
	}
	void  ADD(int x, int y, int c)
	{
		RotateTo(x, 0);
		RotateTo(y + 2, rt);
		int s = ch[ch[rt][1]][0];
		add[s] += c;
		val[s] += c;
		minv[s] += c;
		pushup(ch[rt][1]);
		pushup(rt);
	}
	void  MIN(int x, int y)
	{
		RotateTo(x, 0);
		RotateTo(y + 2, rt);
		int s = ch[ch[rt][1]][0];
		printf("%d\n", minv[s]);
	}
	void  DELETE(int x)
	{
		RotateTo(x , 0);
		RotateTo(x + 2, rt);
		ch[ch[rt][1]][0] = 0;
		pushup(ch[rt][1]);
		pushup(rt);
	}
	void  INSERT(int x, int c)
	{
		RotateTo(x + 1, 0);
		RotateTo(x + 2, rt);
		++tot;
		newnode(ch[ch[rt][1]][0], ch[rt][1], tot, c);
		pushup(ch[rt][1]);
		pushup(rt);
	}
	void  REVOLVE(int x, int y, int c)
	{
		int len = (y - x + 1);
		c = (c%len + len) % len;
		REVERSE(x, y - c);
		REVERSE(y - c + 1, y);
		REVERSE(x, y);
	}
	void debug() { printf("%d\n", rt); Treaval(rt); }
	void Treaval(int x) {
		if (x) {
			pushdown(x);
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d val = %2d\n", x, ch[x][0], ch[x][1], pre[x], sz[x], val[x]);
			Treaval(ch[x][1]);
		}
	}
};
SplayTree spt;
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
		spt.init(n);
		int m;
		scanf("%d", &m);
		while (m--)
		{
			char op[10];
			int x, y, d;
			scanf("%s", op);
			if (op[0] == 'A')
			{
				scanf("%d%d%d", &x, &y, &d);
				spt.ADD(x, y, d);
			}
			else if (op[0] == 'I')
			{
				scanf("%d%d", &x, &d);
				spt.INSERT(x, d);
			}
			else if (op[0] == 'D')
			{
				scanf("%d", &x);
				spt.DELETE(x);
			}
			else if (op[0] == 'M')
			{
				scanf("%d%d", &x, &y);
				spt.MIN(x, y);
			}
			else if (op[3] == 'E')
			{
				scanf("%d%d", &x, &y);
				spt.REVERSE(x, y);
			}
			else
			{
				scanf("%d%d%d", &x, &y, &d);
				spt.REVOLVE(x, y, d);
			}
		}
	}
	return 0;
}
