#include <bits/stdc++.h>
using namespace std;
#define maxn 111111
vector<int>vec[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) vec[i].clear();
        for(int i=0; i<n; i++)
        {
            int m;
            scanf("%d",&m);
            for(int j=0; j<m; j++)
            {
                int num;
                scanf("%d",&num);
                vec[i].push_back(num);
            }
            sort(vec[i].begin(),vec[i].end());
        }
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            int a,b,x,y;
            scanf("%d%d",&a,&b);
            a--,b--;
            if(vec[a].size()<vec[b].size())
            {
                x=a;
                y=b;
            }
            else
            {
                x=b;
                y=a;
            }
            int ans=0,pre=-1;
            for(int i=0; i<vec[x].size(); i++)
            {
                int pos=lower_bound(vec[y].begin(),vec[y].end(),vec[x][i])-vec[y].begin();
                if(i==0)
                {
                    if(pos==0) ans++;
                    else if(pos == vec[y].size()) ans ++ ;
                    else ans+=2;
                }
                else
                if(i==vec[x].size()-1)
                {
                    if(pre!=pos)
                    {
                        if(pos==vec[y].size()) ans++;
                        else ans+=2;
                    }
                }
                else
                {
                    if(pre!=pos)
                    {
                        if(pos==vec[y].size()) ans++;
                        else ans+=2;
                    }
                }
                pre=pos;
            }
            printf("%d\n",ans);
        }
    }
}
