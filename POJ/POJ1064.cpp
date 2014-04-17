#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 10005
double a[MAXN];
int n,k;
bool check(double m)
{
    int ans=0;
    for(int i=0; i<n; i++)
        ans+=(int)(a[i]/m);
    return ans>=k;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        double sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        double l=0,r=sum;
        for(int i=0; i<100; i++)
        {
            double mid=(l+r)/2;
            if(check(mid))
                l=mid;
            else
                r=mid;
        }
        printf("%.2lf\n",floor(r*100)/100);
    }
    return 0;
}
