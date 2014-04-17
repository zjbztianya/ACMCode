// CF294B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f
typedef struct 
{
	int x,y;
}NODE;
NODE a[MAXN],b[MAXN];
int suma[MAXN],sumb[MAXN];
bool cmp(NODE a,NODE b)
{
	return a.y>b.y;
}
int main()
{
	int n,ta=0,tb=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==1)
			a[++ta].x=x,a[ta].y=y;
		else
			b[++tb].x=x,b[tb].y=y;
	}
	sort(a+1,a+ta+1,cmp);
	sort(b+1,b+tb+1,cmp);
	for(int i=1;i<=ta;i++)
		suma[i]=suma[i-1]+a[i].y;
	for(int i=1;i<=tb;i++)
		sumb[i]=sumb[i-1]+b[i].y;
	int ans=INF;
	for(int i=0;i<=ta;i++)
		for(int j=0;j<=tb;j++)
		{
			int tik=i+2*j,w=suma[ta]-suma[i]+sumb[tb]-sumb[j];
			if(w<=tik&&tik<ans)
				ans=tik;
		}
		printf("%d\n",ans);
		return 0;
}

