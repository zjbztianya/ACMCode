#include<bits/stdc++.h>
using namespace std;
#define maxn 211111
int num[maxn];
typedef long long LL;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++) scanf("%d",&num[i]);
        sort(num,num+n);
        printf("%d ",num[n-1]-num[0]);
        int a=0,b=0,pos=0;
        while(pos<n&&num[pos]==num[0])
        {
            a++;
            pos++;
        }
        pos=n-1;
        while(pos>=0&&num[pos]==num[n-1])
        {
            b++;
            pos--;
        }
        LL ans=(LL)a*b;
        if(a==n) ans=(LL)n*(n-1)/2;
        printf("%I64d\n",ans);
    }
}
