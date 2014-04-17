#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 140000
#define NN 10005
#define lson l,m,ls[s]
#define rson m+1,r,rs[s]
int ls[20*MAXN],rs[20*MAXN],cnt[20*MAXN];
int T[MAXN],tot;
int len,n,m;
int num[MAXN];
char op[10010][3];
int a[NN*2],lt[NN],rt[NN],K[NN];
int L[30],R[30];
int N,M;
void build(int l,int r,int &s)
{
    s=++tot;
    cnt[s]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int last,int p,int l,int r,int &s,int d)
{
    s=++tot;
    ls[s]=ls[last],rs[s]=rs[last],cnt[s]=cnt[last]+d;
    if(l==r) return;
    int m=(l+r)>>1;
    if(p<=m) update(ls[last],p,lson,d);
    else     update(rs[last],p,rson,d);

}
int query(int l,int r,int k)
{
    if(l==r) return r;
    int suma=0,sumb=0;
    for(int i=1; i<=N; i++) suma+=cnt[ls[L[i]]];
    for(int i=1; i<=M; i++) sumb+=cnt[ls[R[i]]];
    int m=(l+r)>>1,sum=sumb-suma;
    if(sum>=k)
    {
        for(int i=1; i<=N; i++) L[i]=ls[L[i]];
        for(int i=1; i<=M; i++) R[i]=ls[R[i]];
        return query(l,m,k);
    }
    else
    {
        for(int i=1; i<=N; i++) L[i]=rs[L[i]];
        for(int i=1; i<=M; i++) R[i]=rs[R[i]];
        return query(m+1,r,k-sum);
    }
}
int lowbit(int x)
{
    return x&-x;
}
void BIT(int x,int value,int d)
{
    while(x<=n)
    {
        update(T[x],value,1,len,T[x],d);
        x+=lowbit(x);
    }
}
int BIT_query(int l,int r,int k)
{
    N=0,M=0;
    while(l>0)
    {
        L[++N]=T[l];
        l-=lowbit(l);
    }
    while(r>0)
    {
        R[++M]=T[r];
        r-=lowbit(r);
    }
    return query(1,len,k);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&num[i]);
        a[++len]=num[i];
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%s%d%d",op[i],&lt[i],&rt[i]);
        if(op[i][0]=='Q') scanf("%d",&K[i]);
        else
            a[++len]=rt[i];
    }
    sort(a+1,a+len+1);
    len=unique(a+1,a+len+1)-a-1;
    for(int i=1; i<=n; i++) num[i]=lower_bound(a+1,a+1+len,num[i])-a;
    build(1,len,T[0]);
    for(int i=1; i<=n; i++) BIT(i,num[i],1);
    for(int i=1; i<=m; i++)
        if(op[i][0]=='Q')
            printf("%d\n",a[BIT_query(lt[i]-1,rt[i],K[i])]);
        else
        {
            BIT(lt[i],num[lt[i]],-1);
            int pos=lower_bound(a+1,a+len+1,rt[i])-a;
            num[lt[i]]=pos;
            BIT(lt[i],pos,1);
        }
    return 0;
}
