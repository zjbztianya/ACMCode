#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1005
int a[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        printf("%d\n",a[(n+1)>>1]);
    }
    return 0;
}
