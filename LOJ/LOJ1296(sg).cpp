#include <bits/stdc++.h>
using namespace std;
#define maxn 100
int sg[maxn];
bool vis[maxn];
int SG(int x)
{
    return x&1?SG(x/2):x/2;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            ans^=SG(x);
        }
        printf("Case %d: ",++kase);
        if(ans) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
