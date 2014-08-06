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
#define MAXN 1000005
#define INF 0x3f3f3f3f
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
typedef long long LL;
int a[10];
struct node
{
	int num, pre, dr,pos;
	int seq[10];
	node(int a, int b, int c, int *d,int p)
	{
		num = a;
		pre = b;
		dr = c;
		memcpy(seq, d, sizeof(seq));
		pos = p;
	}
	node(){}
};
int  fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; //i的阶乘为fac[i]
/*  康托展开.
{1...n}的全排列由小到大有序，s[]为第几个数  */
int KT(int n, int s[])
{
	int i, j, t, sum;
	sum = 0;
	for (i = 0; i < n; i++)
	{
		t = 0;
		for (j = i + 1; j < n; j++)
			if (s[j] < s[i])
				t++;
		sum += t*fac[n - i - 1];
	}
	return sum + 1;
}
/*  康托展开的逆运算.
{1...n}的全排列，中的第k个数为s[]  */
node que[MAXN];
bool vis[462880];
int goal;
int ans[MAXN];
void print(int len)
{
	int  cnt = 0;
	while (que[len].pre != -1)
	{
		ans[cnt++] = que[len].dr;
		len = que[len].pre;
	}
	for (int i = cnt - 1; i >= 0; i--)
	{
		if (ans[i] == 0) putchar('l');
		if (ans[i] == 1) putchar('r');
		if (ans[i] == 2) putchar('u');
		if (ans[i] == 3) putchar('d');
	}
}
bool BFS()
{
	int head, tail;
	head = 0;
	tail = 0;
	memset(vis, false, sizeof(vis));
	int t = KT(9, a);
	if (t == goal)return true;
	vis[t] = true;
	int pos;
	for (int i = 0; i < 9; i++) if (a[i] == 9) pos = i;
	que[0] = node(t, -1, -1, a,pos);
	while (head <= tail)
	{
		node cur = que[head];
		for (int j = 0; j < 4; j++)
		{
			int x = cur.pos / 3 + dx[j];
			int y = cur.pos % 3 + dy[j];
			if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
			{
				node now = cur;
				swap(now.seq[cur.pos], now.seq[3 * x + y]);
				int sum = KT(9, now.seq);
				if (vis[sum]) continue;
				vis[sum] = true;
				que[++tail] = node(sum, head, j, now.seq, 3 * x + y);
				if (sum == goal)
				{
					print(tail);
					return true;
				}
			}
		}
		head++;
	}
	return false;
}
int main()
{
	char s[3];
	for (int i = 0; i < 9; i++) a[i] = i + 1;
	goal = KT(9, a);
	while (scanf("%s", s) != EOF)
	{
		if (s[0] != 'x') a[0] = s[0] - '0';
		else a[0] = 9;
		for (int i = 1; i < 9; i++)
		{
			scanf("%s", s);
			if (s[0] != 'x') a[i] = s[0] - '0'; else a[i] = 9;
		}
		bool fg = BFS();
		if (!fg) printf("unsolvable\n");
	}
	return 0;
}



