// GO.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 30005
typedef long long LL;
LL c[MAXN], ans[100005];
int a[MAXN], num[MAXN];
int last[MAXN];
struct node
{
	int L;
	int R;
	int id;
};
node op[100005];
bool cmp(const node a, const node b)
{
	return a.R < b.R;
}
int lowbit(int x)
{
	return x&-x;
}
void add(int x, int d)
{
	while (x < MAXN)
	{
		c[x] += d;
		x += lowbit(x);
	}

}
LL query(int x)
{
	LL ret = 0;
	while (x > 0)
	{
		ret += c[x];
		x -= lowbit(x);
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			num[i] = a[i];
		}
		sort(a + 1, a + n + 1);
		int len = unique(a + 1, a + n + 1) - a - 1;
		for (int i = 1; i <= n; i++) num[i] = lower_bound(a + 1, a + len + 1, num[i]) - a;
		memset(last, -1, sizeof(last));
		memset(c, 0, sizeof(c));
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &op[i].L, &op[i].R);
			op[i].id = i;
		}
		sort(op, op + m, cmp);
		int j = 1;
		for (int i = 0; i < m; i++)
		{
			while (j <= op[i].R)
			{
				if (last[num[j]] != -1)
					add(last[num[j]], -a[num[j]]);
				last[num[j]] = j;
				add(j, a[num[j]]);
				j++;
			}
			ans[op[i].id] = query(op[i].R) - query(op[i].L - 1);
		}
		for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
	}
	return 0;
}

