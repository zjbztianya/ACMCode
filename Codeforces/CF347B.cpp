// CF347B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
map<int,int>ms;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ms[i]=a;
		if(i==a) ans++;
	}
	int add=0;
	for(int i=0;i<n;i++)
		if(ms[ms[i]]==i&&ms[i]!=i) 
		{
			add=2;
			break;
		}
		else
			if(ms[ms[i]]!=i&&ms[ms[i]]!=ms[i])
				add=1;
	printf("%d\n",ans+add);
	return 0;
}

