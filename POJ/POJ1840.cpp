// POJ1840.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#define  MAXN 25000000
short hash[MAXN*2+100];
int main()
{
	int a1,a2,a3,a4,a5;
	short x1,x2,x3,x4,x5;
	long long ans=0;
	scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
	for(x1=-50;x1<=50;x1++)
		for(x2=-50;x2<=50;x2++)
			for(x3=-50;x3<=50;x3++)
				if(x1!=0&&x2!=0&&x3!=0)
				{
					int sum=x1*x1*x1*a1+x2*x2*x2*a2+a3*x3*x3*x3;
					hash[sum+MAXN]++;
				}
				for(x4=-50;x4<=50;x4++)
					for(x5=-50;x5<=50;x5++)
						if(x4!=0&&x5!=0)
						{
							int sum=-(a4*x4*x4*x4+a5*x5*x5*x5);
							ans+=hash[sum+MAXN];
						}
						printf("%I64d\n",ans);
						return 0;
}


