// CF344C.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
typedef long long LL;
using namespace std;
int main()
{
	LL a,b,ans=0;
	cin>>a>>b;
	while(b)
	{
		ans+=a/b;
		LL t=a;
		a=b;
		b=t%b;
	}
	cout<<ans<<"\n";
	return 0;
}

