#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 55
int a[MAXN];
int main()
{
    int n,kase=0,first=true;
    while(scanf("%d",&n)!=EOF&&n)
    {
        if(!first) printf("\n");
        else  first=false;
        int ave=0;
           for(int i=0;i<n;i++)
           {
               scanf("%d",&a[i]);
               ave+=a[i];
           }
           ave/=n;
           int ans=0;
           for(int i=0;i<n;i++) if(a[i]>ave) ans+=a[i]-ave;
           printf("Set #%d\n",++kase);
           printf("The minimum number of moves is %d.\n",ans);
    }
    return 0;
}
