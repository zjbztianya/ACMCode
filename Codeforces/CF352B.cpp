#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
using namespace std;
#define MAXN 100005
#define INF 0x3f3f3f3f
struct node
{
    int val,id;
} ;
node a[MAXN];
vector<int>ivec[MAXN];
bool cmp(node a,node b)
{
    if(a.val==b.val) return a.id<b.id;
    return a.val<b.val;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i].val);
        a[i].id=i+1;
        ivec[i].clear();
    }
    sort(a,a+n,cmp);
    int t=0;
    for(int i=0; i<n; i++)
    {
        int j=i+1;
        ivec[t].push_back(a[i].val);
        ivec[t].push_back(a[i].id);
        while(j<n&&a[j].val==a[i].val)
        {
            ivec[t].push_back(a[j].id);
            j++;
        }
        i=j-1;
        t++;
    }
    pair<int,int>ip[MAXN];
    int len=0;
    for(int i=0; i<t; i++)
    {
        map<int,int>ms;
        for(int j=2; j<ivec[i].size(); j++) ms[ivec[i][j]-ivec[i][j-1]]++;
        if(ivec[i].size()==2) ip[len++]=make_pair(ivec[i][0],0);
        else if(ms[ivec[i][2]-ivec[i][1]]==ivec[i].size()-2)
            ip[len++]=make_pair(ivec[i][0],ivec[i][2]-ivec[i][1]);
    }
    printf("%d\n",len);
    for(int i=0; i<len; i++)
        printf("%d %d\n",ip[i].first,ip[i].second);
    return 0;
}
