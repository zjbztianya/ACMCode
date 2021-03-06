#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1005
typedef long long LL;
LL c[2][2][MAXN][MAXN];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int y,int v)
{
    for(int i=x; i<MAXN; i+=lowbit(i))
        for(int j=y; j<MAXN; j+=lowbit(j))
            c[x&1][y&1][i][j]^=v;
}
LL query(int x,int y)
{
    LL ret=0;
    for(int i=x; i>0; i-=lowbit(i))
        for(int j=y; j>0; j-=lowbit(j))
            ret^=c[x&1][y&1][i][j];
    return ret;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int op,x1,x2,y1,y2;
        scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
        if(op==1)
        {

            LL ans=query(x2,y2)^query(x1-1,y2)^query(x2,y1-1)^query(x1-1,y1-1);
            printf("%I64d\n",ans);
        }
        else
        {
            LL v;
            scanf("%I64d",&v);
            add(x1,y1,v);
            add(x2+1,y1,v);
            add(x1,y2+1,v);
            add(x2+1,y2+1,v);
        }
    }
    return 0;
}
