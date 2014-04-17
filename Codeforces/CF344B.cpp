// CF344B.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ansa,ansb,ansc;
	ansb=b-a+c;
	ansa=a+b-c;
	ansc=a-b+c;
	if(ansa>=0&&ansb>=0&&ansc>=0&&ansb%2==0&&ansa%2==0&&ansc%2==0)
		printf("%d %d %d\n",ansa/2,ansb/2,ansc/2);
		else
			printf("Impossible\n");
	return 0;
}

