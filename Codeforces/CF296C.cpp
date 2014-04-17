// CF296C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  MAXN 100005
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
#define x first
#define y second
typedef long long LL;
pair<pair<int,int>,LL> op[MAXN];
LL a[MAXN],addv[MAXN<<2],sumv[MAXN<<2];
void PushDown(int s,int opr)
{
	if(opr==1)
	{
		if(addv[s])
		{
			addv[s<<1]+=addv[s];
			addv[s<<1|1]+=addv[s];
			addv[s]=0;
		}
	}
	else
	{
		if(sumv[s])
		{
			sumv[s<<1]+=sumv[s];
			sumv[s<<1|1]+=sumv[s];
			sumv[s]=0;
		}
	}
}
void update(int opr,int ql,int qr,LL d,int l,int r,int s)
{
	if(ql<=l&&r<=qr)
	{
		if(opr==1)addv[s]+=d;
		else
			sumv[s]+=d;
		return;
	}
	PushDown(s,opr);
	int m=(l+r)>>1;
	if(ql<=m) update(opr,ql,qr,d,lson);
	if(qr>m)  update(opr,ql,qr,d,rson);
}
LL query(int opr,int p,int l,int r,int s)
{
	if(l==r)
	{
		if(opr==1)
			return addv[s];
		else
			return sumv[s];
	}
	PushDown(s,opr);
	int m=(l+r)>>1;
	LL ans=0;
	if(p<=m) ans=query(opr,p,lson);
	else
		ans=query(opr,p,rson);
	return ans;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&op[i].x.x,&op[i].x.y,&op[i].y);
	while(k--)
	{
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		update(2,xx,yy,1,1,m,1);
	}
	for(int i=1;i<=m;i++)
		op[i].y*=query(2,i,1,m,1);
	for(int i=1;i<=m;i++)
		update(1,op[i].x.x,op[i].x.y,op[i].y,1,n,1);
	for(int i=1;i<=n;i++)
		printf("%I64d ",a[i]+query(1,i,1,n,1));
	printf("\n");
	return 0;
}

