// CF342A.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,d,e,n;
	scanf("%d",&n);
	a=b=c=d=e=0;
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		if(p==5||p==7)
		{
			printf("-1\n");
			return 0;
		}
		if(p==1) a++;else 
			if(p==2) b++;else
				if(p==3) c++;else
					if(p==4) d++;else
						if(p==6) e++;
	}
	if(a!=d+e||b+c!=a||b!=e+d-c||e<0||b<d||c>e)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		for(int i=0;i<d;i++) printf("1 2 4\n");
		for(int i=0;i<b-d;i++) printf("1 2 6\n");
		for(int i=0;i<c;i++) printf("1 3 6\n");
	}
	return 0;
}

