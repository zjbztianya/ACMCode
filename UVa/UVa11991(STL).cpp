#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
#define maxn 111111
int num[maxn],a[maxn];
vector<int>vec[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num[i]);
            a[i]=num[i];
        }
        for(int i=0; i<maxn; i++)  vec[i].clear();
        sort(a,a+n);
        int len=unique(a,a+n)-a;
        for(int i=0; i<n; i++)
        {
            int idx=lower_bound(a,a+len,num[i])-a;
            vec[idx].push_back(i+1);
        }
        while(m--)
        {
            int k,v;
            scanf("%d %d",&k,&v);
            v=lower_bound(a,a+len,v)-a;
            if(v==len)
            {
                puts("0");
                continue;
            }
            if(vec[v].size()<k) puts("0");
            else printf("%d\n",vec[v][k-1]);
        }
    }
    return 0;
}
