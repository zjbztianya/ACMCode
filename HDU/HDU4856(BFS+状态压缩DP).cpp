// 7.17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 16
#define INF 0x3f3f3f
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};
int visit[MAXN][MAXN],d[MAXN][MAXN][MAXN][MAXN];
int mp[MAXN][MAXN];
int dp[1<<MAXN][MAXN];
struct node 
{
	int x,y,tx,ty;
};
node a[MAXN];
int n,m;
void BFS(int sx,int sy)
{
	int q[2][1000];
	int head,tail,i,tx,ty;
	memset(q,0,sizeof(q));
	memset(visit,0,sizeof(visit));
	head=0;
	tail=1;
	q[0][tail]=sx;
	q[1][tail]=sy;
	visit[sx][sy]=1;
	d[sx][sy][sx][sy]=0;
	while(head<tail)
	{
		head++;
		tx=q[0][head];
		ty=q[1][head];
		for(i=0; i<4; i++)
		{
			int px=tx+dx[i];
			int py=ty+dy[i];
			if(px>=1&&px<=n&&py>=1&&py<=n&&!visit[px][py]&&!mp[px][py]&&d[sx][sy][tx][ty]!=INF)
			{
				tail++;
				q[0][tail]=px;
				q[1][tail]=py;
				visit[px][py]=1;
				d[sx][sy][px][py]=d[sx][sy][tx][ty]+1;
			}
		}
	}
}
void DP()
{
	memset(dp,0x3f3f3f,sizeof(dp));
	for(int i=0;i<m;i++) dp[1<<i][i]=0;
	for(int s=0;s<(1<<m);s++) 
	{
		for(int i=0;i<m;i++)
			if((s&(1<<i))&&dp[s][i]!=INF)
				for(int j=0;j<m;j++)
					if(!(s&(1<<j)))
					{
						int msk=s|(1<<j);
						dp[msk][j]=min(dp[msk][j],dp[s][i]+d[a[i].tx][a[i].ty][a[j].x][a[j].y]);
						//if(s==(1<<m)-1) printf("%d\n",dp[s][i]);
					}
	}
}
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
		{
			char s[30];
			scanf("%s",s);
			for(int j=0;j<n;j++)
				if(s[j]=='#') mp[i][j+1]=1;

		}
		memset(d,INF,sizeof(d));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) if(!mp[i][j]) BFS(i,j);
		for(int i=0;i<m;i++)  scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].tx,&a[i].ty);
		DP();
		int ans=INF;
		for(int i=0;i<m;i++) ans=min(ans,dp[(1<<m)-1][i]);
		if(ans==INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}

