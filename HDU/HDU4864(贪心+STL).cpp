#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
#define maxn 105
vector<int>vec[maxn];
struct node
{
    int x,y;
    int num;
};
node a[maxn*100];
bool cmp(node a,node b)
{
    return a.num>b.num;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<maxn; i++) vec[i].clear();
        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            vec[b].push_back(a);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].num=500*a[i].x+2*a[i].y;
        }
        for(int i=0; i<=100; i++)
            sort(vec[i].begin(),vec[i].end());
            sort(a,a+m,cmp);
        int cnt;
        LL ans;
        cnt=ans=0;
        for(int i=0; i<m; i++)
        {
              for(int j=a[i].y;j<=100;j++)
              if(vec[j].size())
              {
                  vector<int>::iterator pos=lower_bound(vec[j].begin(),vec[j].end(),a[i].x);
                 if(pos!=vec[j].end())
                 {
                       cnt++;
                       ans+=a[i].num;
                       vec[j].erase(pos);
                       break;
                 }
              }
        }
        printf("%d %I64d\n",cnt,ans);
    }
    return 0;
}
