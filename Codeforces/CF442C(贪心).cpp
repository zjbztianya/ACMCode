#include <bits/stdc++.h>
using namespace std;
#define maxn 533333
#define MOD 1000000007
typedef long long LL;
int num[maxn],ans[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++) scanf("%d",&num[i]);
        int cnt=0;
        LL sum=0;
        for(int i=1; i<=n; i++)
        {
            while(cnt>1&&ans[cnt-2]>=ans[cnt-1]&&ans[cnt-1]<=num[i])
            {
                sum+=min(ans[cnt-2],num[i]);
                cnt--;
            }
            ans[cnt++]=num[i];
        }
        sort(ans,ans+cnt);
        for(int i=0; i<cnt-2; i++) sum+=ans[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
