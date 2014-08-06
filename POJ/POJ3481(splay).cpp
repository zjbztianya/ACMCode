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
	int num[maxn];
	int pre[maxn];
	int sz[maxn];
	int rt, tot;
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
	void newnode(int &x, int f, int c, int d)
	{
		x = ++tot;
		ch[x][0] = ch[x][1] = 0;
		pre[x] = f;
		val[x] = c;
		num[x] = d;
		sz[x] = 1;
	}
	void init()
	{
		memset(sz, 0, sizeof(sz));
		ch[0][0] = ch[0][1] = sz[0] = pre[0] = val[0] = num[0] = 0;
		rt = tot = 0;
		newnode(rt, 0, -INF, INF);
		newnode(ch[rt][1], rt, INF, INF - 1);
		pushup(rt);
	}
	void getmin()
	{
		RotateTo(2, 0);
	}
	void getmax()
	{
		RotateTo(sz[rt] - 1, 0);
	}
	void ins(int c, int k)
	{
		int x = rt;
		while (ch[x][val[x] < k])
		{
			x = ch[x][val[x] < k];
		}
		newnode(ch[x][val[x] < k], x, k, c);
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
	int op;
	spt.init();
	while (scanf("%d", &op) && op)
	{
		if (op == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			spt.ins(x, y);
			//spt.debug();
		}
		else if (op == 2)
		{
			if (spt.sz[spt.rt] == 2)
			{
				printf("0\n");
				continue;
			}
			spt.getmax();
			printf("%d\n", spt.num[spt.rt]);
			spt.delrt();
			//spt.debug();
		}
		else
		{
			if (spt.sz[spt.rt] == 0)
			{
				printf("0\n");
				continue;
			}
			spt.getmin();
			printf("%d\n", spt.num[spt.rt]);
			spt.delrt();
			//spt.debug();
		}
	}
	return 0;
}


