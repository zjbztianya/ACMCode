#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 160
int pos[MAXN],ans[MAXN];
int main()
{
    for(int k=1; k<=155; k++)
    {
        int m;
        pos[0]=0;
        for(m=1;; ++m)
        {
            int i;
            for(i=1; i<k-1; i++)
            {
                pos[i]=(pos[i-1]-1+m)%(k-i);
                if(pos[i]<1) break;
            }
            if(i>=k-1) break;
        }
        ans[k]=m;
    }
    int k;
    while(scanf("%d",&k)!=EOF&&k)
        printf("%d\n",ans[k]);
    return 0;
}

