#include <bits/stdc++.h>
using namespace std;
#define maxn 11111
vector< pair<int,int> >vec[maxn],ans[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<maxn; i++)
        {
            vec[i].clear();
            ans[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            int num[111],k;
            scanf("%d",&k);
            if(k==0) continue;
            for(int j=0; j<k; j++)
            {
                scanf("%d",&num[j]);
                num[j]--;
            }
            for(int j=0; j<k; j++)
            {
                int x;
                scanf("%d",&x);
                vec[i].push_back(make_pair(num[j],x));
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<vec[i].size(); j++)
            {
                ans[vec[i][j].first].push_back(make_pair(i,vec[i][j].second));
            }
        }
        printf("%d %d\n",m,n);
        for(int i=0; i<m; i++)
        {
            int sz=ans[i].size();
            if(sz==0)
            {
                printf("0\n\n");
                continue;
            }
            printf("%d",sz);
            for(int j=0; j<sz; j++) printf(" %d",ans[i][j].first+1);
            printf("\n");
            for(int j=0; j<sz-1; j++) printf("%d ",ans[i][j].second);
            printf("%d\n",ans[i][sz-1].second);
        }
    }
    return 0;
}
