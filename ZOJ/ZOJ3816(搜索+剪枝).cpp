#include<bits/stdc++.h>
using namespace std;
#define maxn 11111
typedef long long LL;
int num[20],len,ans[20];
LL n;
LL getsum()
{
    LL ret=0;
    for(int i=0; i<len; i++) ret=ret*10+ans[i];
    return ret;
}
LL dfs(int l,int r,int e)
{
    if(l-r>1) return -1;
    if(l-r==1)
    {
        LL t=getsum();
        if(t<n) return t;
        else return -1;
    }
    int u=e?num[l]:9;
    LL ret=0;
    for(int d=u; d>=0; d--)
    {
        ans[l]=d;
        if((l==0||ans[l]!=ans[l-1])&&!(r-l==0)&&!(l==0&&d==0))
        {
            for(int k=1; k<=r-l; k++)
            {
                ans[r-k+1]=d;
                ret=max(ret,dfs(l+1,r-k,e&&d==u));
            }
        }
        else ret=max(ret,dfs(l+1,r,e&&d==u));
        if(ret>0) return ret;//搜到立马返回！
    }
    return ret;
}
LL cal(LL n)
{
    memset(ans,0,sizeof(ans));
    len=0;
    while(n)
    {
        num[len++]=n%10;
        n/=10;
    }
    reverse(num,num+len);
    return dfs(0,len-1,1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld\n",cal(n));
    }
    return 0;
}
