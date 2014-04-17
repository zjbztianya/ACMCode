#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100005
int c[MAXN];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int d)
{
    while(x<MAXN)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    int m,op,a,k;
    while(scanf("%d",&m)!=EOF)
    {
        memset(c,0,sizeof(c));
        while(m--)
        {
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d",&a);
                add(a,1);
            }
            else if(op==1)
            {
                scanf("%d",&a);
                if(query(a)-query(a-1)>0)
                    add(a,-1);
                else
                    printf("No Elment!\n");
            }
            else
            {
                scanf("%d%d",&a,&k);
                int l=a+1,r=MAXN-1,ans=-1,sum=query(a);
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(query(mid)-sum>=k)
                    {
                        ans=mid;
                        r=mid-1;
                    }
                    else
                        l=mid+1;
                }
                if(ans!=-1) printf("%d\n",ans);
                else
                    printf("Not Find!\n");
            }
        }
    }
    return 0;
}

