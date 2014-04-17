// CF347A.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 105
int a[MAXN];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	swap(a[0],a[n-1]);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
    return 0;
}

