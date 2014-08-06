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
#define maxn 222222
typedef long long LL;
int tot;
struct node
{
	char op[6];
	int num;
};
node go[maxn];
int pos[maxn];
int st[maxn], en[maxn];
struct SplayTree
{
	int ch[maxn][2];
	int pre[maxn];
	int sz[maxn];
	int rt;
	int cnt[maxn];
	
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
	int get_kth(int k)
	{
		int x = rt,ret;
		for (;;)
		{
			int tmp = sz[ch[x][0]];
			if (tmp < k&&k <= tmp + cnt[x])
			{
				ret = st[x] + k - tmp - 1;
				break;
			}
			if (k <= tmp) x = ch[x][0];
			else
			{
				k -= (tmp + cnt[x]);
				x = ch[x][1];
			}
		}
		return ret;
	}
	void RotateTo(int k, int goal)
	{
		int x = Bin(get_kth(k));
		Splay(x, goal);
	}
	void newnode(int &x, int f, int k)
	{
		x = k;
		ch[x][0] = ch[x][1] = 0;
		pre[x] = f;
		sz[x] = en[x]-st[x]+1;
		cnt[x] = sz[x];
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
		ch[0][0] = ch[0][1] = sz[0] = pre[0] = cnt[0] = 0; 
		rt = 0;
		makeTree(rt, 1, n, 0);
	}
	void pushup(int x)
	{
		sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
	}
	void delrt()
	{
		int t = rt;
		if (ch[t][1])
		{
			 rt = ch[t][1];
			 pre[rt] = 0;
             RotateTo(1, 0);
			 ch[rt][0] = ch[t][0];
			 pre[ch[rt][0]] = rt;
		}
		else rt = ch[t][0];
		pre[rt] = 0;	
		if(rt) pushup(rt);
	}
	void Top(int x)
	{
		
		int r = Bin(x);
		Splay(r, 0);
		delrt();
		RotateTo(1, 0);
		pre[rt] = r;
		ch[r][0] = 0;
		ch[r][1] = rt;
		rt = r;
		pre[rt] = 0;	
		pushup(rt);
	}
	int Bin(int x)
	{
		int l, r;
		l = 1; r = tot;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (st[mid] <= x&&x <= en[mid]) return mid;
			if (x < st[mid]) r = mid - 1; 
			else l = mid + 1;
		}
	}
	int query(int x)
	{
		int y = Bin(x);
		Splay(y, 0);
		return sz[ch[y][0]] + x - st[y]+1;
	}
	void debug() { printf("%d\n", rt); Treaval(rt); }
	void Treaval(int x) {
		if (x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d \n", x, ch[x][0], ch[x][1], pre[x], sz[x]);
			Treaval(ch[x][1]);
		}
	}
};
SplayTree spt;
int main()
{
	int T,kase=0;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("Case %d:\n", ++kase);
		int cnt = 0;
		cnt = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%s%d", &go[i].op, &go[i].num);
			if (go[i].op[0] == 'T')
			{
				pos[cnt++] = go[i].num;
			}
		}
		if (n == 1)
		{
			for (int i = 0; i < m; i++) if (go[i].op[0] != 'T') printf("1\n");
			continue;
		}
		pos[cnt++] = 1;
		pos[cnt++] = n;
		sort(pos, pos + cnt);
		cnt = unique(pos, pos + cnt) - pos;
		tot = 0;
		for (int i = 0; i < cnt; i++)
		{
			if (i - 1>=0 && pos[i] - pos[i - 1] > 1)
			{
				st[++tot] = pos[i - 1] + 1;
				en[tot] = pos[i] - 1;
			}
				st[++tot] = pos[i];
				en[tot] = pos[i];
		}
		spt.init(tot);
		for (int i = 0; i < m; i++)
		{
			
			if (go[i].op[0] == 'T')
			{
				spt.Top(go[i].num);
			}
			else if (go[i].op[0]=='Q')
			{
				printf("%d\n", spt.query(go[i].num));
			}
			else
			{
				printf("%d\n", spt.get_kth(go[i].num));
			}
		}
	}
	return 0;
}
