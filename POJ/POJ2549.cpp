// POJ2549.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
#define  MAXN 1005
set<int> iset;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		iset.clear();
		for(int i=0;i<n;i++)
		{
			int p;
			scanf("%d",&p);
			iset.insert(p);
		}
		vector<int> ivec(iset.begin(),iset.end());
		n=ivec.size();
		bool flag=false;
		for(int i=n-1;i>=0&&!flag;i--)
		{
			for(int j=0;j<=n-3&&!flag;j++)
				if(i!=j){
					int k=j+1,l=n-1;
					while(k<l)
					{
						long long ans=ivec[j]+ivec[k]+ivec[l];
						if(ivec[i]==ans)
						{
							if(i==k||i==l) break;
							printf("%d\n",ivec[i]);
							flag=true;
							break;
						}
						else
							if(ans<ivec[i]) k++;
							else
								l--;
					}
				}
		}
		if(!flag)
			printf("no solution\n");
	}
	return 0;
}

