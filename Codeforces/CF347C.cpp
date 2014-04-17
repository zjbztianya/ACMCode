#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n,d,a,maxs=0;
    scanf("%d",&n);
    d=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        if(a>maxs) maxs=a;
        d=gcd(d,a);
    }
    if((maxs/d-n)%2!=0)
        printf("Alice\n");
    else
        printf("Bob\n");
    return 0;
}
