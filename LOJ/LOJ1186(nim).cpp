/*************************************************************************
	> File Name: LOJ1186.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月12日 星期二 10时46分20秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 111
int a[maxn],b[maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        for(int i=1; i<=n; i++) scanf("%d",&b[i]);
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            ans^=(b[i]-a[i]-1);
        }
        if(ans) printf("Case %d: white wins\n",++kase);
        else printf("Case %d: black wins\n",++kase);
    }
    return 0;
}

