#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define maxn 2111
typedef long long LL;
map<int,int>id,mp;
deque<int>que[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n,kase=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        printf("Scenario #%d\n",++kase);
        mp.clear();
        id.clear();
        for(int i=0; i<maxn; i++)
        {
            while(!que[i].empty()) que[i].pop_back();
        }
        for(int i=1; i<=n; i++)
        {
            int cnt;
            scanf("%d",&cnt);
            for(int j=0; j<cnt; j++)
            {
                int x;
                scanf("%d",&x);
                id[x]=i;
            }
        }
        char op[15];
        int tot=1;
        while(scanf("%s",op)!=EOF)
        {
            if(op[0]=='S') break;
            if(op[0]=='E')
            {
                int x;
                scanf("%d",&x);
                if(mp[id[x]]&&!que[mp[id[x]]].empty())
                {
                    que[mp[id[x]]].push_back(x);
                }
                else
                {
                    mp[id[x]]=tot++;
                    que[mp[id[x]]].push_back(x);
                }
            }
            else
            {
                for(int i=1; i<=tot; i++)
                {
                    if(que[i].size()!=0)
                    {
                        printf("%d\n",que[i].front());
                        que[i].pop_front();
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
