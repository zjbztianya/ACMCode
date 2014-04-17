// POJ3254.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  MAXN 15
#define MOD 100000000
int dp[MAXN][1<<MAXN],line[MAXN];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(line,0,sizeof(line));
		for(int i=1;i<=n;i++)
			for(int j=0;j<m;j++) 
			{
				int a;
				scanf("%d",&a);
				line[i]|=a<<j;
			}
			memset(dp,0,sizeof(dp));
			dp[0][0]=1;
			for(int i=1;i<=n;i++)
				for(int j=0;j<(1<<m);j++)
					if((j&line[i])==j&&((j&(j>>1))==0))
						for(int k=0;k<(1<<m);k++)
							if((j&k)==0)
								dp[i][j]+=dp[i-1][k];
			int ans=0;
			for(int i=0;i<(1<<m);i++)
				ans+=dp[n][i];
			printf("%d\n",ans%MOD);
	}
	return 0;
}

