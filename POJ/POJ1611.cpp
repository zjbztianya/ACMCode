#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 30005
int f[MAXN];
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=0; i<n; i++) f[i]=i;
        while(m--)
        {
            int k,a;
            scanf("%d",&k);
            scanf("%d",&a);
            int u=find(a);
            for(int i=0; i<k-1; i++)
            {
                int b;
                scanf("%d",&b);
                int v=find(b);
                if(u!=v) f[v]=u;
            }
        }
        int v=find(0),ans=1;
        for(int i=1; i<n; i++)
        {
            int u=find(i);
            if(u==v) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
