// CF337A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int a[55];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d",&a[i]);
	sort(a,a+m);
	int ans=INF;
	for(int i=n-1;i<m;i++)
	ans=min(ans,a[i]-a[i-n+1]);
	printf("%d\n",ans);
	return 0;
}

