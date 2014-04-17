// HDU4737.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 100005
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
int sumv[MAXN<<2],a[MAXN];
void PushUp(int s)
{
	sumv[s]=sumv[s<<1]|sumv[s<<1|1];
}
void build(int l,int r,int s)
{
	if(l==r) {
		sumv[s]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUp(s);
}
int query(int ql,int qr,int l,int r,int s)
{
	if(ql<=l&&r<=qr)
		return sumv[s];
	int m=(l+r)>>1;
	int ans=0;
	if(ql<=m) ans=ans|query(ql,qr,lson);
	if(qr>m)  ans=ans|query(ql,qr,rson);
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		int n,m;
		long long ans=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		build(0,n-1,1);
		for(int i=0;i<n;i++)
		{
			if(a[i]>=m) continue;
			int l=i,r=n-1;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				int sum=query(i,mid,0,n-1,1);
				if(sum>=m) r=mid-1;
				else
					l=mid+1;
			}
			ans+=r-i+1;
		}
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}
