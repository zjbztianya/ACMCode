#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 111111
typedef long long LL;
int num[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)  scanf("%d",&num[i]);
        for(int k=0; k<m; k++)
        {
            int x;
            scanf("%d",&x);
            nth_element(num,num+k,num+x);
            printf("%d\n",num[k]);
        }
        if(T) puts("");
    }
}
