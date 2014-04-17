#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f
struct node
{
    int b,p;
};
node a[MAXN][MAXN];
int cnt[MAXN];
bool cmp(const node x,const node y)
{
    return x.b<y.b;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d",&m);
        int mins=INF,maxs=INF;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&cnt[i]);
            for(int j=0; j<cnt[i]; j++)
                scanf("%d%d",&a[i][j].b,&a[i][j].p);
            sort(a[i],a[i]+cnt[i],cmp);
            if(a[i][0].b<mins) mins=a[i][0].b;
            if(a[i][cnt[i]-1].b<maxs) maxs=a[i][cnt[i]-1].b;
        }
        int b,p;
        double ans=0;
        for(int num=mins; num<=maxs; num=b+1)
        {
            b=INF,p=0;
            for(int i=0; i<m; i++)
            {
                int t=0;
                while(a[i][t].b<num) t++;
                for(int j=t; j<cnt[i]; j++)
                    if(a[i][j].p<a[i][t].p) t=j;
                b=min(b,a[i][t].b);
                p+=a[i][t].p;
            }
            ans=max(ans,(double)b/p);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
