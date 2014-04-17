#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define  MAXN 1005
bool visit[MAXN][MAXN];
struct node
{
    int x,y;
};
node pr[MAXN];
int a[MAXN][MAXN];
int main()
{
    int cnt,n,m,p;
    memset(visit,false,sizeof(visit));
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            scanf("%d",&a[i][j]);
    }
    cnt=0;
    if(p==0)
    {
        for(int i=1; i<m; i++)
            for(int j=i+1; j<=m; j++)
                for(int k=1; k<=n; k++)
                    if(a[k][i]>a[k][j])
                    {
                        swap(a[k][i],a[k][j]);
                        if(!visit[i][j])
                        {
                            visit[i][j]=true;
                            pr[cnt].x=i;
                            pr[cnt++].y=j;
                        }
                    }
    }
    else
    {
        for(int i=1; i<m; i++)
            for(int j=i+1; j<=m; j++)
                for(int k=1; k<=n; k++)
                    if(a[k][i]<a[k][j])
                    {
                        swap(a[k][i],a[k][j]);
                        if(!visit[i][j])
                        {
                            visit[i][j]=true;
                            pr[cnt].x=j;
                            pr[cnt++].y=i;
                        }
                    }
    }
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++) printf("%d %d\n",pr[i].x,pr[i].y);
    return 0;
}
