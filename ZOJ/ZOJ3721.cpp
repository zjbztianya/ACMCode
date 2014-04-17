// ZOJ3721.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
#define MAXN 100005
typedef struct  
{
	int s;
	int t;
	int id;
}NODE;
NODE a[MAXN];
vector<int> ivec[MAXN];
bool cmp(NODE x,NODE y)
{
	  if(x.s==y.s) return x.t<y.t;
	  return x.s<y.s;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<MAXN;i++) ivec[i].clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].s,&a[i].t);
			a[i].t--;
			a[i].id=i+1;
		}
		sort(a,a+n,cmp);
		int l,r,ans=0;
		l=a[0].s;r=a[0].t;
	    ivec[0].push_back(a[0].id);
		for(int i=1;i<n;i++)
		{
			  int kl=max(l,a[i].s);
			  int kr=min(r,a[i].t);
			  if(kl<=kr)
			  {
				  ivec[ans].push_back(a[i].id);
				  l=kl,r=kr;
			  }
			  else
			  {
				     ans++;
					 l=a[i].s,r=a[i].t;
					 ivec[ans].push_back(a[i].id);
			  }
		}
		printf("%d\n",ans+1);
		for(int i=0;i<=ans;i++)
		{
			   for(int j=0;j<ivec[i].size();j++)
				   if(!j) printf("%d",ivec[i][j]);
				   else
				   printf(" %d",ivec[i][j]);
			   printf("\n");
		}
		printf("\n");
	}
	return 0;
}

