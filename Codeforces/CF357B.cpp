#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 300005
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
int setv[MAXN<<2],sumv[MAXN<<2];
void PushDown(int s)
{
    if(setv[s])
    {
        setv[s<<1]=setv[s<<1|1]=setv[s];
    }
}
void PushUp(int s)
{
    sumv[s]=sumv[s<<1]+sumv[s<<1|1];
}
void update(int ql,int qr,int d,int l,int r,int s)
{
    if(sumv[s]==r-l+1) return;
    if(ql<=l&&r<=qr&&sumv[s]==0)
    {
        setv[s]=d;
        sumv[s]=r-l+1;
        return;
    }
    int m=(l+r)>>1;
    if(ql<=m) update(ql,qr,d,lson);
    if(qr>m) update(ql,qr,d,rson);
    PushUp(s);
}
void query(int l,int r,int s)
{
    if(l==r)
    {
        printf("%d ",setv[s]);
        return;
    }
    PushDown(s);
    int m=(l+r)>>1;
    query(lson);
    query(rson);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        int l,r,num;
        scanf("%d%d%d",&l,&r,&num);
        if(num-1>=l)update(l,num-1,num,1,n,1);
        if(num+1<=r) update(num+1,r,num,1,n,1);
    }
    query(1,n,1);
    printf("\n");
    return 0;
}
