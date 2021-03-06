#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int>x[maxn],y[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        x[a].push_back(b),y[b].push_back(a);
    }
    for(int i=0; i<=100000; i++)
    {
        sort(x[i].begin(),x[i].end());
        sort(y[i].begin(),y[i].end());
    }
    int ans=0;
    for(int i=0; i<=100000; i++)
        for(int j=0; j<x[i].size(); j++)
        {
             int tx=i,ty=x[i][j],w=j+1;
             int h=upper_bound(y[ty].begin(),y[ty].end(),tx)-y[ty].begin();
             while(h<y[ty].size()&&w<x[tx].size())
             {
                 if(x[tx][w]-ty>y[ty][h]-tx) h++;
                 else if(x[tx][w]-ty<y[ty][h]-tx) w++;
                 else
                 {
                     ans+=binary_search(x[y[ty][h]].begin(),x[y[ty][h]].end(),x[tx][w]);
                     h++,w++;
                 }
             }
        }
        printf("%d\n",ans);
    return 0;
}
