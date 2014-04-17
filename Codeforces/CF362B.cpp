#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 3005
int a[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
        scanf("%d",&a[i]);
    sort(a,a+m);
    if(a[0]==1||a[m-1]==n)
    {
        printf("NO\n");
        return 0;
    }
    bool flag=true;
    for(int i=0; i<m-2; i++)
    {
        if(a[i+1]-a[i]==1&&a[i+2]-a[i+1]==1)
        {
            flag=false;
            break;
        }
    }
    if(flag) printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
