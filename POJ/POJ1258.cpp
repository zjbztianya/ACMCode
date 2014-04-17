#include<stdio.h>
#include<string.h>
#define MAXS 1000005
long w[105][105];
int d[105];
int visit[105];
int n;
long min,ans;
void prim()
{
    int i,j,k;
    d[1]=0;
    memset(visit,0,sizeof(visit));
    for(i=2; i<=n; i++)
        d[i]=w[1][i];
    visit[1]=1;
    for(i=2; i<=n; i++)
    {
        min=MAXS;
        for(j=2; j<=n; j++)
            if(!visit[j]&&d[j]<min)
            {
                min=d[j];
                k=j;
            }
        visit[k]=1;
        for(j=2; j<=n; j++)
            if(!visit[j]&&w[k][j]<d[j])
                d[j]=w[k][j];
    }

}
void print()
{
    int i;
    ans=0;
    for(i=2; i<=n; i++)
        ans+=d[i];
    printf("%ld\n",ans);
}
int main(void)
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                scanf("%ld",&w[i][j]);
        prim();
        print();
    }
    return 0;
}
