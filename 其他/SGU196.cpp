#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
#define maxn 11111
int deg[maxn];
int main()
{
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
      memset(deg,0,sizeof(deg));
      for(int i=0;i<m;i++)
      {
          int x,y;
          scanf("%d%d",&x,&y);
          deg[x]++;
          deg[y]++;
      }
      LL ans=0;
      for(int i=1;i<=n;i++) ans+=deg[i]*deg[i];
      printf("%I64d\n",ans);
  }
  return 0;
}
