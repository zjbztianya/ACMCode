/*************************************************************************
	> File Name: LOJ1192.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月12日 星期二 16时18分42秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
          for(int i=0;i<2*n;i+=2)
          {
              int a,b;
              scanf("%d%d",&a,&b);
              ans^=(b-a-1);
          }
          printf("Case %d: ",++kase);
          if(ans) printf("Alice\n"); else printf("Bob\n");
    }
}

