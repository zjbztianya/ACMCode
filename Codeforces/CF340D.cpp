#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 100005
int a[MAXN],g[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
        g[0]=a[0];
        int len=0;
        for(int i=1;i<n;i++)
            if(a[i]>g[len])g[++len]=a[i];
            else
            {
                int pos=lower_bound(g,g+len,a[i])-g;
                g[pos]=a[i];
            }
        printf("%d\n",len+1);
    return 0;
}
