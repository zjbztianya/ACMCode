// SGU223.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 11
typedef long long LL;
LL dp[MAXN][1<<MAXN][MAXN*10];
int s[1<<MAXN],cnt,sum[1<<MAXN];
int get_sum(int x)
{
	int ret=0;
	while(x)
	{
		ret+=(x&1);
		x>>=1;
	}
	return ret;
}
void pre_solve(int n)
{
	for(int i=0;i<(1<<n);i++)
		if(!(i&(i>>1)))
		{
			s[cnt]=i;
			sum[cnt++]=get_sum(i);
		}
}
bool check(int a,int b)
{
	if(a&b) return false;
	if((a>>1)&b) return false;
	if((a<<1)&b) return false;
	return true;
}
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(dp,0,sizeof(dp));
		cnt=0;
		pre_solve(n);
		for(int i=0;i<cnt;i++)
		{
			dp[1][i][sum[i]]=1;
		}
		for(int i=2;i<=n;i++)
			for(int a=0;a<cnt;a++)
				for(int b=0;b<cnt;b++)
					for(int c=sum[a];c<=k;c++)
						if(check(s[a],s[b]))
							dp[i][a][c]+=dp[i-1][b][c-sum[a]];
		LL ans=0;
		for(int i=0;i<cnt;i++)
			ans+=dp[n][i][k];
		printf("%I64d\n",ans);
	}
	return 0;
}

