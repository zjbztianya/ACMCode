#include <bits/stdc++.h>
using namespace std;
#define maxn 22222
#define EPS 1e-8
double a[maxn],c[maxn];
struct node
{
    double d,c;
};
node num[maxn];
double cal(double x,int n)
{
    double ret=0;
    for(int i=1; i<=n; i++)
        ret+=fabs(x-num[i].d)*num[i].c;
    return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        double L=0,R=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lf%lf",&num[i].d,&num[i].c);
            R=max(R,num[i].d);
        }
        double ans;
        for(int i=0; i<1000; i++)
        {
            double m1=L+(R-L)/3;
            double m2=R-(R-L)/3;
            if(cal(m1,n)<cal(m2,n)) R=m2;
            else L=m1;
        }
        printf("%.5lf\n",L);
    }
    return 0;
}
