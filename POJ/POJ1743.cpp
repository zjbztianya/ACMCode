// POJ1743.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 20005
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i<m;i++) ws[i]=0;
	for(i=0;i<n;i++) ws[x[i]=r[i]]++;
	for(i=1;i<m;i++) ws[i]+=ws[i-1];
	for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
	for(j=1,p=1;p<n;j*=2,m=p)
	{
		for(p=0,i=n-j;i<n;i++) y[p++]=i;
		for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
		for(i=0;i<n;i++) wv[i]=x[y[i]];
		for(i=0;i<m;i++) ws[i]=0;
		for(i=0;i<n;i++) ws[wv[i]]++;
		for(i=1;i<m;i++) ws[i]+=ws[i-1];
		for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
	}
	return;
}
int rank[maxn],height[maxn];
void calheight(int *r,int *sa,int n)
{
	int i,j,k=0;
	for(i=1;i<=n;i++) rank[sa[i]]=i;
	for(i=0;i<n;height[rank[i++]]=k)
		for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	return;
}

bool check(int *sa,int n,int k)
{
	int i,max=sa[1],min=sa[1];
	for(i=2;i<=n;i++)
	{
		if(height[i]<k) max=min=sa[i];
		else
		{
			if(sa[i]<min) min=sa[i];
			if(sa[i]>max) max=sa[i];
			if(max-min>k) return true;
		}
	}
	return false;
}
int r[maxn],sa[maxn];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int j;
		scanf("%d",&j);
		n--;
		for(int i=0;i<n;i++)
		{
			int k;
			scanf("%d",&k);
			r[i]=k-j+100;
			j=k;
		}
		r[n]=0;
		da(r,sa,n+1,200);
		calheight(r,sa,n);
		int l=0,r=n/2,k=0;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if(check(sa,n,mid))
			{
				k=mid;
				l=mid+1;
			}
			else r=mid-1;

		}
		if(k>=4) printf("%d\n",k+1);
		else printf("0\n");
	}
	return 0;
}


