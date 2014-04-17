#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstring>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f
int dp_max[MAXN][MAXN],dp_min[MAXN][MAXN];
int num[MAXN];
char op[MAXN][5];
bool visit_max[MAXN][MAXN],visit_min[MAXN][MAXN];
int dfs_min(int l,int r);
int dfs_max(int l,int r);
int dfs_min(int l,int r)
{
    if(visit_min[l][r]) return dp_min[l][r];
    visit_min[l][r]=true;
    if(l==r) return dp_min[l][r]=num[l];
    for(int k=l; k<r; k++)
    {
        int min_x=dfs_min(l,k);
        int min_y=dfs_min(k+1,r);
        int max_x=dfs_max(l,k);
        int max_y=dfs_max(k+1,r);
        if(op[k+1][0]=='t') dp_min[l][r]=min(dp_min[l][r],min_x+min_y);
        else
        {
            dp_min[l][r]=min(dp_min[l][r],min(min_x*max_y,max_x*min_y));
            dp_min[l][r]=min(dp_min[l][r],min(min_x*min_y,max_x*max_y));
        }

    }
    return dp_min[l][r];
}
int dfs_max(int l,int r)
{
    if(visit_max[l][r]) return dp_max[l][r];
    visit_max[l][r]=true;
    if(l==r) return dp_max[l][r]=num[l];
    for(int k=l; k<r; k++)
    {
        int min_x=dfs_min(l,k);
        int min_y=dfs_min(k+1,r);
        int max_x=dfs_max(l,k);
        int max_y=dfs_max(k+1,r);
        if(op[k+1][0]=='t') dp_max[l][r]=max(dp_max[l][r],max_x+max_y);
        else  dp_max[l][r]=max(dp_max[l][r],max(min_x*min_y,max_x*max_y));
    }
    return dp_max[l][r];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp_max,-INF,sizeof(dp_max));
        memset(dp_min,INF,sizeof(dp_min));
        memset(visit_max,false,sizeof(visit_max));
        memset(visit_min,false,sizeof(visit_min));
        for(int i=0; i<n; i++)
        {
            scanf("%s",op[i]);
            strcpy(op[i+n],op[i]);
            scanf("%d",&num[i]);
            num[i+n]=num[i];
        }
        int ans=-INF;
        for(int i=0; i<n; i++)
            ans=max(ans,dfs_max(i,i+n-1));
        printf("%d\n",ans);
        int first=true;
        for(int i=0; i<n; i++)
            if(dfs_max(i,i+n-1)==ans)
            {
                if(first)
                {
                    printf("%d",i+1);
                    first=false;
                }
                else
                    printf(" %d",i+1);
            }
        printf("\n");
    }
    return 0;
}


