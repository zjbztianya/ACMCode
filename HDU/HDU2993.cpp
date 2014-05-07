#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 100005
typedef long long LL;
int q[maxn];
LL sum[maxn];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        sum[0]=0;
        for(int i=1; i<=n; i++)
        {
            int num;
            scanf("%d",&num);
            sum[i]=sum[i-1]+num;
        }
        int head,tail;
        head=0,tail=-1;
        double ans=0;
        for(int i=k; i<=n; i++)
        {
            while(head<tail&&(sum[i-k]-sum[q[tail]])*(q[tail]-q[tail-1])<=(sum[q[tail]]-sum[q[tail-1]])*(i-k-q[tail])) tail--;
            q[++tail]=i-k;
            while(head<tail&&(sum[i]-sum[q[head]])*(i-q[head+1])<=(sum[i]-sum[q[head+1]])*(i-q[head])) head++;
            ans=max(ans,(sum[i]-sum[q[head]])*1.0/(i-q[head]));
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
