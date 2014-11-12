#include <bits/stdc++.h>
using namespace std;
#define maxn 1000005
typedef long long LL;
int cntl[maxn],cntr[maxn];
map<int,int>mp;
int num[maxn];
int c[maxn];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int n)
{
    if(x==0) return;
    while(x<=n)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
LL query(int x)
{
    LL ret=0;
    if(x==0) return 0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        memset(cntl,0,sizeof(cntl));
        memset(cntr,0,sizeof(cntr));
        memset(c,0,sizeof(c));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num[i]);
            cntl[i]=mp[num[i]]+1;

            mp[num[i]]++;
        }
        mp.clear();
        for(int i=n-1; i>=0; i--)
        {
            cntr[i]=mp[num[i]]+1;
            mp[num[i]]++;
        }
        LL ans=0;
        for(int i=n-1; i>=0; i--)
        {
            ans+=query(cntl[i]-1);
            add(cntr[i],n);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
