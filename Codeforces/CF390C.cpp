#include <bits/stdc++.h>
using namespace std;
#define maxn 111111
int sum[maxn],cnt[maxn];
char str[maxn];
int main()
{
    int n,k,w;
    while(scanf("%d%d%d",&n,&k,&w)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        scanf("%s",str+1);
        for(int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+str[i]-'0';
            if(i-k>=0) cnt[i]=cnt[i-k];
            if(str[i]-'0'==1) cnt[i]++;
        }
        while(w--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int tmp=(r-l+1)/k;
            tmp-=(cnt[r]-cnt[l-1]);
            printf("%d\n",tmp+sum[r]-sum[l-1]-(cnt[r]-cnt[l-1]));
        }
    }
    return 0;
}
