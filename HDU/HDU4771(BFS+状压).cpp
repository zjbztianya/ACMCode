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
#define MAXN 105
#define INF 0x3f3f3f3f
const int dx[4] = { 0, 0, -1, 1 };
const int dy[4] = { -1, 1, 0, 0 };
typedef long long LL;
int mp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int dp[1 << 10][10];
int n, m;
pair<int, int>p[10];
struct node
{
	int x, y, d;
	node(int a, int b, int c)
	{
		x = a; y = b; d = c;
	}
	node(){}
};
queue< node >que;
int BFS(int sx, int sy)
{
	int ans = INF;
	memset(vis, false, sizeof(vis));
	dis[sx][sx] = 0;
	while (!que.empty()) que.pop();
	vis[p[sx].first][p[sx].second]= true;
	que.push(node(p[sx].first,p[sx].second,0));
	while (!que.empty())
	{
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx >= 1 && tx <= n&&ty >= 1 && ty <= m&&!mp[tx][ty] && !vis[tx][ty])
			{
				que.push(node(tx,ty,d+1));
				if (tx == p[sy].first&&ty == p[sy].second) return d + 1;
				vis[tx][ty] = true;
			}
		}
	}
	return ans;
}
void DP(int tot)
{
	memset(dp, INF, sizeof(dp));
	for (int i = 0; i < tot; i++) dp[1 << i][i] = dis[tot][i];
	for (int s = 0; s < (1 << tot); s++)
	{
		for (int j = 0; j < tot; j++)
		{
			if (dp[s][j] != INF && (s&(1 << j)))
			{
				for (int i = 0; i < tot; i++)
				{
					if (!(s&(1 << i)))
					{
						dp[s | (1 << i)][i] = min(dp[s | (1 << i)][i], dp[s][j] + dis[i][j]);
					}
				}
			}
		}
	}
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF&&n + m)
	{
		int sx, sy;
		memset(mp, 0, sizeof(mp));
		for (int i = 1; i <= n; i++)
		{
			char s[MAXN];
			scanf("%s", s);
			for (int j = 0; j < m; j++)
				if (s[j] == '#') mp[i][j + 1] = 1;
				else
				{
					if (s[j] == '@') sx = i, sy = j + 1;
				}
		}
		int tot;
		scanf("%d", &tot);
		memset(dis, INF, sizeof(dis));
		for (int i = 0; i < tot; i++) scanf("%d%d", &p[i].first, &p[i].second);
		p[tot].first = sx; p[tot].second = sy;
		for (int i = 0; i <= tot; i++)
		{
			for (int j = 0; j <= tot; j++)
				if (i!=j)
				dis[i][j] = BFS(i, j);
				else dis[i][j] = 0;
		}
		DP(tot);
		int ans = INF;
		for (int i = 0; i < tot; i++) ans = min(ans, dp[(1 << tot) - 1][i]);
		if (ans != INF) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}



