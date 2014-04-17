// CF13C.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define MAXN 5005
#define  INF 0x3f3f3f3f
typedef long long LL;
LL dp[MAXN],a[MAXN],b[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(j==1)dp[j]+=abs(a[i]-b[j]);
			else
				dp[j]=min(dp[j-1],dp[j]+abs(a[i]-b[j]));
		}
		printf("%I64d\n",dp[n]);
		return 0;
}
