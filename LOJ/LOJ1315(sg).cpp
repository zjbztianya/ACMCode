#include <bits/stdc++.h>
using namespace std;
#define maxn 1111
const int dx[6]= {1,-1,-1,-2,-2,-3};
const int dy[6]= {-2,-2,-3,-1,1,-1};
int sg[maxn][maxn];

int SG(int i,int j)
{
    int& s=sg[i][j];
    if(~s) return s;
    bool vis[10]= {false};
    for(int k=0; k<6; k++)
    {
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&y>=0)
        {
            vis[SG(x,y)]=true;
        }
    }
    for(int k=0; ; k++)
    {
        if(!vis[k])
        {
            s=k;
            break;
        }
    }
    return s;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    memset(sg,-1,sizeof(sg));
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ans^=SG(x,y);
        }
        printf("Case %d: ",++kase);
        if(ans) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
