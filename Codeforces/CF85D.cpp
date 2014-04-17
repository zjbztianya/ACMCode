// CF85D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long LL;
vector<int> a;
int main()
{

	int n;
	char s[15];
	while(scanf("%d",&n)!=EOF)
	{
		a.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			if(s[0]=='s')
			{
				LL ans=0;
				for(int i=2;i<a.size();i+=5)
					ans+=a[i];
				printf("%I64d\n",ans);
			}
			else
			{
				int p;
				scanf("%d",&p);
				if(s[0]=='a') a.insert(lower_bound(a.begin(),a.end(),p),p);
				else
					a.erase(lower_bound(a.begin(),a.end(),p));
			}
		}
	}
	return 0;
}

