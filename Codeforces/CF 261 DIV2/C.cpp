#include<bits/stdc++.h>
using namespace std;
#define maxn 1111
typedef long long LL;
int ans[maxn][maxn];
int main()
{
    int n,k,d;
    scanf("%d%d%d",&n,&k,&d);
    int tmp=1;
    bool y=false;
    for(int i=0; i<d; i++)
    {
        tmp*=k;
        if(tmp>=n)
        {
            y=true;
            break;
        }
    }
    if(!y) printf("-1\n");
    else
    {
        for(int  s=0; s<n; s++)
        {
            int num=s;
            int cnt=0;
            while(num)
            {
                ans[s][cnt++]=num%k;
                num/=k;
            }
        }
        for(int i=0; i<d; i++)
        {
            for(int j=0; j<n; j++) printf("%d ",ans[j][i]+1);
            printf("\n");
        }
    }
    return 0;
}
