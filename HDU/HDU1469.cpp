// HDU1469.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#define  MAXN 1000000
int hash[MAXN*2+100];
int main()
{
	int a1,a2,a3,a4;
	while(scanf("%d%d%d%d",&a1,&a2,&a3,&a4)!=EOF)
	{
		if((a1>0&&a2>0&&a3>0&&a4>0)||(a1<0&&a2<0&&a3<0&&a4<0))
		{
			  printf("0\n");
			  continue;
		}
		memset(hash,0,sizeof(hash));
		long long ans=0;
		for(int x1=1;x1<=100;x1++)
			for(int x2=1;x2<=100;x2++)
			{
				int sum=x1*x1*a1+x2*x2*a2;
				hash[sum+MAXN]++;
			}
			for(int x3=1;x3<=100;x3++)
				for(int x4=1;x4<=100;x4++)
				{
					int sum=-(a4*x4*x4+a3*x3*x3);
					ans+=hash[sum+MAXN];
				}
			
				printf("%I64d\n",ans*16);
	}
	return 0;
}

