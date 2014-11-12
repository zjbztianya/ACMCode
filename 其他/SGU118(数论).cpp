#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int ans=0,m=1;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            int x;
            scanf("%d",&x);
            x%=9;
            m=(m*x)%9;
            ans=(ans+m)%9;
        }
        if(ans==0) ans=9;
        printf("%d\n",ans);
    }
}
