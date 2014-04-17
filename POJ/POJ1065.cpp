#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
#define MAXN 5005
pair<int,int> a[MAXN];
bool visit[MAXN];
bool cmp(const pair<int,int>x,const pair<int,int>y)
{
    if(x.first==y.first) return x.second<y.second;
    return x.first<y.first;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        memset(visit,false,sizeof(visit));
        for(int i=0; i<n; i++)
            scanf("%d%d",&a[i].first,&a[i].second);
        sort(a,a+n,cmp);
        int ans=0;
        for(int i=0; i<n; i++)
            if(!visit[i])
            {
                ans++;
                int k=i;
                for(int j=i+1; j<n; j++)
                    if(!visit[j]&&a[k].second<=a[j].second)
                    {
                        visit[j]=true;
                        k=j;
                    }
            }
        printf("%d\n",ans);
    }
    return 0;
}

