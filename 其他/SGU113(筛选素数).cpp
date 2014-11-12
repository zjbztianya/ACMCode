#include <bits/stdc++.h>
using namespace std;
#define maxn 111111
bool flag[maxn];
int prime[maxn],cnt;
void init()
{
    memset(flag,false,sizeof(flag));
    flag[0]=true;
    flag[1]=true;
    cnt=0;
    for(int i=2; i<maxn; i++)
    {
        if(!flag[i])
            prime[cnt++]=i;
        for(int j=0; j<cnt&&i*prime[j]<maxn; ++j)
        {
            flag[i*prime[j]]=true;
            if(i%prime[j]==0) break;
        }
    }
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int x;
            scanf("%d",&x);
            bool y=false;
            for(int i=0; i<cnt; i++)
            {
                if(x%prime[i]==0)
                {
                    int num=x/prime[i];
                    if(num==1) continue;
                    int t=sqrt(num+0.5);
                    bool ok=true;
                    for(int i=2; i<=t; i++)
                        if(num%i==0)
                        {
                            ok=false;
                            break;
                        }
                    if(ok)
                    {
                        y=true;
                        break;

                    }
                }
            }
            if(y) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
