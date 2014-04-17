#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 205
int cnt[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b) swap(a,b);
            if(a&1) a++;
            if(b&1) b++;
            a/=2,b/=2;
            for(int j=a;j<=b;j++) cnt[j]++;
        }
        int ans=*max_element(cnt,cnt+205);
        printf("%d\n",ans*10);
    }
    return 0;
}
