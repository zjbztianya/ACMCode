#include <bits/stdc++.h>
using namespace std;
#define maxn 55
int num[maxn][maxn];
int sg[maxn][maxn][maxn];
int SG(int c,int l,int r,int *a)
{
    int &s=sg[c][l][r];
    if(~s) return s;
    if(l==r) return 1;
    bool vis[maxn];
    memset(vis,false,sizeof(vis));
    for(int i=l; i<=r; i++)
    {
        int fg[maxn];
        memset(fg,0,sizeof(fg));
        fg[r+1]=1;
        for(int j=l; j<=r; j++) if(a[j]>=a[i]) fg[j]=1;
        int st=-1;
        int x=0;
        for(int j=l; j<=r+1; j++)
        {
            if(st==-1&&!fg[j]) st=j;
            if(st>=l&&fg[j]) x^=SG(c,st,j-1,a);
            if(fg[j]) st=-1;
        }
        vis[x]=true;
    }
    for(int i=0;; i++)
    {
        if(!vis[i])
        {
            s=i;
            break;
        }
    }
    return s;
}
struct node
{
    int x,y;
    node(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    node() {}
    bool operator <(const struct node &dd) const
    {
        if(dd.x==x) return y<dd.y;
        return x<dd.x;
    }
};
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        memset(sg,-1,sizeof(sg));
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num[i][0]);
            for(int j=1; j<=num[i][0]; j++) scanf("%d",&num[i][j]);
        }
        int wins=0;
        for(int i=0; i<n; i++)
        {
            wins^=SG(i,1,num[i][0],num[i]);
        }
        printf("Case %d: ",++kase);
        if(!wins) printf("Genie\n");
        else
        {
            set<node>setv;
            printf("Aladdin\n");
            setv.clear();
            for(int i=0; i<n; i++)
            {
                for(int j=1; j<=num[i][0]; j++)
                {

                    int ans=0;
                    for(int k=0; k<n; k++)
                        if(k!=i)
                        {
                            ans^=SG(k,1,num[k][0],num[k]);
                        }
                    int fg[maxn];
                    memset(fg,0,sizeof(fg));
                    fg[num[i][0]+1]=1;
                    for(int k=1; k<=num[i][0]; k++) if(num[i][k]>=num[i][j]) fg[k]=1;
                    int st=-1;
                    for(int k=1; k<=num[i][0]+1; k++)
                    {
                        if(st==-1&&!fg[k]) st=k;
                        if(st>=1&&fg[k]) ans^=SG(i,st,k-1,num[i]);
                        if(fg[k]) st=-1;
                    }
                    if(ans==0)
                    {
                        setv.insert(node(i+1,num[i][j]));
                    }
                }
            }
            for(set<node>::iterator it=setv.begin(); it!=setv.end(); ++it)
                printf("(%d %d)",it->x,it->y);
            printf("\n");
        }
    }
    return 0;
}
