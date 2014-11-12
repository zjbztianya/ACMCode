
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
using namespace std;
#define  maxn 100005
#define  INF 0x3f3f3f3f
typedef long long LL;
deque<int>num[333];
int cnt[333][maxn];
int lastans,Block,n;
int tran(int x)
{
	return (x + lastans - 1) % n+1;
}
void update(int l, int r)
{
	int x = l / Block, y = r / Block;
		int tmp = num[y][r%Block];
		num[y].erase(num[y].begin()+r%Block);
		cnt[y][tmp]--;
		for (int i = y-1; i >=x; i--)
		{
			int t = num[i].back();
			num[i].pop_back();
			cnt[i][t]--;
			num[i + 1].push_front(t);
			cnt[i + 1][t]++;
		}
		num[x].insert(num[x].begin() + l%Block,tmp);
		cnt[x][tmp]++;
}
int query(int l, int r, int k)
{
	int x = l / Block, y = r / Block;
	int ans = 0;
	if (x == y)
	{
		for (int i = l%Block; i <= r%Block; i++)
			ans += num[x][i] == k;
	}
	else
	{
		for (int i = l%Block; i < Block; i++) ans += num[x][i] == k;
		for (int i = 0; i <= r%Block; i++) ans += num[y][i] == k;
		for (int i = x + 1; i <= y - 1; i++) ans += cnt[i][k];
	}
	return ans;
}
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		Block = 300;
			//(int)sqrt(n*1.0 + 0.5);
		for (int i = 0; i < 333; i++) num[i].clear();
		memset(cnt, 0, sizeof(cnt));
		lastans = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			num[i / Block].push_back(x);
			cnt[i / Block][x]++;
		}
		int m;
		scanf("%d", &m);
		while (m--)
		{
			int op, l, r, k;
			scanf("%d", &op);
			if (op == 1)
			{
				scanf("%d%d", &l, &r);
				l = tran(l), r = tran(r);
				if (l>r) swap(l, r);
				l--, r--;
				update(l, r);
			}
			else
			{
				scanf("%d%d%d", &l, &r, &k);
				l = tran(l), r = tran(r), k = tran(k);
				if (l > r) swap(l, r);
				l--, r--;
				printf("%d\n",lastans=query(l, r, k));
			}
		}
	}
	return 0;
}

