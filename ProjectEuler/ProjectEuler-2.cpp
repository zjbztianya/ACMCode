// ProjectEuler-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	int f1,f2,f3,ans=2;
	f1=1,f2=2;f3=3;
	while(f3<=4000000)
	{
		if(f3%2==0)ans+=f3;
		f1=f2;
		f2=f3;
		f3=f1+f2;
	}
	cout<<ans<<endl;
	return 0;
}

