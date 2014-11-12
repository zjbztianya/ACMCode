#include<bits/stdc++.h>
using namespace std;
#define maxn 111111
typedef long long LL;
int c[maxn],cnt[maxn];
int n;
int lowbit(int x)
{
    return x&-x;
}
void update(int x,int d)
{
    while(x<=n)
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
    int q,flag=1;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++)
    {
        cnt[i]=1;
        update(i,1);
    }
    int st=1,ed=n;
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int x;
            scanf("%d",&x);
            if(ed-st+1<2*x)
            {
                flag^=1;
                x=ed-st+1-x;
            }
            if(flag)
            {
                for(int i=1; i<=x; i++)
                {
                    cnt[st+2*x-i]+=cnt[st+i-1];
                    update(st+2*x-i,cnt[st+i-1]);
                }
                st+=x;
            }
            else
            {
                for(int i=0; i<x; i++)
                {
                    cnt[ed-2*x+1+i]+=cnt[ed-i];
                    update(ed-2*x+1+i,cnt[ed-i]);
                }
                ed-=x;
            }
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(flag) printf("%d\n",query(st+r-1)-query(st+l-1));
            else printf("%d\n",query(ed-l)-query(ed-r));
        }
    }
    return 0;
}
