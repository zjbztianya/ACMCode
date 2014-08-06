// GO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
// GO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 111111
typedef long long LL;
struct SplayTree
{
	int ch[maxn][2];
	int val[maxn];
	int pre[maxn];
	int sz[maxn];
	int rt, tot, tp;
	void  Rotate(int x, int f)
	{
		int y = pre[x];
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
	void RotateTo(int k, int goal)
	{
		int x;
		for (x = rt;;)
		{
			int tmp = sz[ch[x][0]];
			if (tmp + 1 == k) break;
			if (k <= tmp) x = ch[x][0];
			else
			{
				k -= (tmp + 1);
				x = ch[x][1];
			}
		}
		Splay(x, goal);
	}
	void newnode(int &x, int f, int c)
	{
		x = ++tot;
		ch[x][0] = ch[x][1] = 0;
		pre[x] = f;
		val[x] = c;
		sz[x] = 1;
	}
	void init()
	{
		memset(sz, 0, sizeof(sz));
		ch[0][0] = ch[0][1] = sz[0] = pre[0] = val[0];
		rt = tot = 0;
		tp = -1;
		newnode(rt, 0, -INF);
		newnode(ch[rt][1], rt, INF);
		pushup(rt);
	}
	int get_pre()
	{
		int x = ch[rt][0];
		while (ch[x][1])
		{
			x = ch[x][1];
		}
		return x;
	}
	int get_suc()
	{
		int x = ch[rt][1];
		while (ch[x][0])
		{
			x = ch[x][0];
		}
		return x;
	}
	void ins(int k)
	{
		int x = rt;
		while (ch[x][val[x] < k])
		{
			x = ch[x][val[x] < k];
		}
		newnode(ch[x][val[x] < k], x,k);
		Splay(ch[x][val[x] < k], 0);
	}
	void pushup(int x)
	{
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
	}
	void delrt()
	{
		int t = rt;
		rt = ch[t][1];
		pre[rt] = 0;
		RotateTo(1, 0);
		ch[rt][0] = ch[t][0];
		pre[ch[rt][0]] = rt;
		pushup(rt);
	}
	void debug() { printf("%d\n", rt); Treaval(rt); }
	void Treaval(int x) {
		if (x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d\n", x, ch[x][0], ch[x][1], pre[x], sz[x], val[x]);
			Treaval(ch[x][1]);
		}
	}
};
SplayTree spt;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) != EOF)
	{
		LL ans = 0;
		spt.init();
		while (n--)
		{
			int op, num;
			scanf("%d%d", &op, &num);
			if (spt.sz[spt.rt] == 2)
			{
				spt.tp = op;
				spt.ins(num);
			}
			else if (spt.tp == op)
			{
				spt.ins(num);
			}
			else
			{
				spt.ins(num);
				int a = spt.get_pre();
				int b = spt.get_suc();
				int numa, numb;
				if (spt.val[a] == -INF) numa = INF;
				else numa = num - spt.val[a];
				if (spt.val[b] == INF) numb = INF;
				else numb = spt.val[b] - num;
				spt.delrt();
				if (numa <= numb)
				{
					ans = (ans + numa) % 1000000;
					spt.Splay(a, 0);
					spt.delrt();
				}
				else
				{
					ans = (ans + numb) % 1000000;
					spt.Splay(b, 0);
					spt.delrt();
				}
			}
		}
		printf("%I64d\n", ans % 1000000);
	}
	return 0;
}




