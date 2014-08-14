/*************************************************************************
	> File Name: LOJ1247.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月12日 星期二 16时31分02秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,ans=0;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=0; j<m; j++)
            {
                int x;
                scanf("%d",&x);
                sum+=x;
            }
            ans^=sum;
        }
        printf("Case %d: ",++kase);
        if(ans) printf("Alice\n");
        else printf("Bob\n");
    }
}

