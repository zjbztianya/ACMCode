#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 4005
#define ESP 1e-6
#define INF 0x3f3f3f3f
int main()
{
    int n;
    scanf("%d",&n);
    double suma=0,sumb=0;
    int lena=0,lenb=0;
    for(int i=0; i<2*n; i++)
    {
        double a;
        scanf("%lf",&a);
        suma+=a;
        if(fabs(a-((int)a))<ESP) lena++;
        sumb+=floor(a);
    }
    lenb=2*n-lena;
    double sum=suma-sumb;
    int k=min(n,lenb);
    double ans=INF;
    for(int i=0; i<=k; i++)
        if(i+lena>=n)
            ans=min(ans,fabs(sum-i*1.0));
    printf("%.3lf\n",ans);
    return 0;
}
