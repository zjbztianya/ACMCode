#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a1,a2,a3,b1,b2,b3;
    while(scanf("%d%d%d",&a1,&a2,&a3)!=EOF)
    {
        scanf("%d%d%d",&b1,&b2,&b3);
        int a,b;
        a=a1+a2+a3;
        b=b1+b2+b3;
        scanf("%d",&n);
        int ans=(a+4)/5+(b+9)/10;
        if(ans>n) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}