// HDU4745.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1005
short dp[MAXN][MAXN];
short a[MAXN];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		for(int i=0;i<n;i++) dp[i][i]=1;
		for(int i=n-1;i>=0;i--)
			for(int j=i+1;j<n;j++)
				if(a[i]==a[j])
					dp[i][j]=dp[i+1][j-1]+2;
				else
					dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
		int ans=1;
		for(int i=0;i<n-1;i++) ans=max(ans,dp[0][i]+dp[i+1][n-1]);
		printf("%d\n",ans);
	}
	return 0;
}

