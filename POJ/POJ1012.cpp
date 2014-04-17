#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 20
int pos[40],ans[40];
int main()
{
    for(int k=1; k<=13; k++)
    {
        int m;
        pos[0]=0;
        for(m=1;; ++m)
        {
            bool flag=true;
            for(int i=1; i<=k; i++)
            {
                pos[i]=(pos[i-1]-1+m)%(2*k-i+1);
                if(pos[i]<k)
                {
                    flag=false;
                    break;
                }
            }
            if(!flag) continue;
            int cnt=0;
            for(int i=1; i<=k; i++)
                if(pos[i]>=k&&pos[i]<=2*k-1) cnt++;
            if(cnt==k) break;
        }
        ans[k]=m;
    }
    int k;
    while(scanf("%d",&k)!=EOF&&k)
        printf("%d\n",ans[k]);
    return 0;
}

