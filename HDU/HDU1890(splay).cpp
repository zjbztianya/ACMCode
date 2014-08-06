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
	int pre[maxn];
	int sz[maxn];
	int rev[maxn];
	int rt;
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
	void RotateTo(int k, int goal)
	{
		int x=rt;
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
		Splay(x, goal);
	}
	void newnode(int &x, int f, int k )
	{
		x =k;
		ch[x][0] = ch[x][1] = 0;
		pre[x] = f;
		sz[x] = 1;
		rev[x] = 0;
	}
    void makeTree(int &x, int l, int r, int f) {
		if (l > r) return;
		int m = (l + r) >> 1;
		newnode(x, f, m);
		makeTree(ch[x][0], l, m - 1, x);
		makeTree(ch[x][1], m + 1, r, x);
		pushup(x);
	}
	void init(int n)
	{
		ch[0][0] = ch[0][1] = sz[0] = pre[0] =rev[0]=0;
		rt =0;
		newnode(rt, 0,n+1);
		newnode(ch[rt][1], rt, n+2);
		makeTree(ch[ch[rt][1]][0], 1, n , ch[rt][1]);
		pushup(ch[rt][1]);
		pushup(rt);
	}
	void pushup(int x)
	{
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
	}
	void go_rev(int x)
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
			rev[x] = 0;
		}
	}
	int get_next(int x)
	{
		pushdown(x);
		x = ch[x][1];
		while (ch[x][0])
		{
			x = ch[x][0];
			pushdown(x);
		}
		return x;
	}
};
SplayTree spt;
struct ND
{
	int num, id;
};
ND node[maxn];
bool cmp(ND a, ND b)
{
	if (a.num == b.num) return a.id < b.id;
	else
	return a.num < b.num;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n==0) break;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &node[i].num);
			node[i].id = i;
		}
		sort(node + 1, node + n + 1, cmp);
		spt.init(n);
		for (int i = 1; i <= n; i++)
		{
			spt.Splay(node[i].id, 0);
			printf("%d", spt.sz[spt.ch[spt.rt][0]]);
			if (i < n) printf(" ");
			spt.RotateTo(i, 0);
			spt.Splay(spt.get_next(node[i].id),spt.rt);
			spt.go_rev(spt.ch[spt.ch[spt.rt][1]][0]);
		}
		printf("\n");
	}
	return 0;
}
