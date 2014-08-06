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
#define maxn 105
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
typedef long long LL;
int a[maxn],n;
bool vis[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
bool fg;
void  dfs(int cur,int cur_len,int len,int dep)
{
	if (fg) return;
	if (cur_len == 0)
	{
		int pos = 0;
		while (vis[pos]) pos++;
		vis[pos] = true;
		dfs(pos+1, a[pos], len, dep + 1);
		vis[pos] = false;
		return;
	}
	if (cur_len == len)
	{
		if (dep == n)
		{
			fg = true;
		}
		else
		dfs(0, 0, len, dep );
		return;
	}
	for (int i = cur; i < n; i++)
	{
			if (!vis[i] && a[i] + cur_len <= len)
			{
				if (!vis[i - 1] && a[i - 1] == a[i]) continue;
			   vis[i] = true;
			   dfs(i+1, a[i] + cur_len, len, dep + 1);
			   vis[i] = false;
			}
	}
}
int main()
{
	while (scanf("%d", &n) != EOF&&n)
	{
		int sum = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sort(a, a + n, cmp);
		int ans = sum;
		for (int i = a[0];  i<= sum/2; i++)
		{
			if (sum%i==0)
			{
				memset(vis, false, sizeof(vis));
				fg = false;
				dfs(0,0,i,0);
				if (fg) 
				{
					ans = i;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}




