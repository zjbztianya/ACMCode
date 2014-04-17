#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define EPS 1e-3
int main()
{
    double sum;
    while(scanf("%lf",&sum)!=EOF)
    {
        if(sum<EPS) break;
        double ans=0;
        int n=0;
        while(sum-ans>EPS)
        {
            n++;
            ans+=1.0/(n+1.0);
        }
        printf("%d card(s)\n",n);
    }
    return 0;
}
