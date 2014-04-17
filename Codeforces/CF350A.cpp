#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define INF 0x3f3f3f3f
int a[105],v;
int main()
{
    int n,m,minv=INF,b;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0; i<m; i++)
    {
        scanf("%d",&b);
        minv=min(minv,b);
    }
    if(a[0]*2>a[n-1])
    {
        printf("-1\n");
        return 0;
    }
    else v=a[n-1];
    if(minv<=v) printf("-1\n");
    else
        printf("%d\n",v);
    return 0;
}
