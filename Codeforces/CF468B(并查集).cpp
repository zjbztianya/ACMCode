#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
#include <set>
#include <sstream>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111111
typedef long long LL;
map<int, int>mp;
int fa[maxn];
int num[maxn];
int find(int x)
{
    return x == fa[x] ? x : fa[x]=find(fa[x]);
}
void meg(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b) fa[a] = b;
}
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    int n,a,b;
    while (scanf("%d%d%d",&n,&a,&b)!=EOF)
    {
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            fa[i] = i;
            mp[num[i]] = i;
        }
        fa[n + 1] = n + 1;
        fa[n + 2] = n + 2;
        for (int i = 1; i <= n; i++)
        {
            if (mp[a - num[i]])
            {
                meg(i, mp[a - num[i]]);
            }
            else meg(i, n + 1);
            if (mp[b - num[i]])
            {
                meg(i, mp[b - num[i]]);
            }
            else
            {
                meg(i, n + 2);
            }
        }
        if (find(n + 1) != find(n+2))
        {
            puts("YES");
            for (int i = 1; i <= n; i++)
            {
                if (find(i) == find(n+2))
                {
                    printf("0 ");
                }
                else
                {
                    printf("1 ");
                }
            }
            puts("");
        }
        else puts("NO");
    }
    return 0;
}
