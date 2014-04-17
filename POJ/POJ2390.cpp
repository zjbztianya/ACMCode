#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double r,m;
    int y;
    while(scanf("%lf%lf%d",&r,&m,&y)!=EOF)
    {
        for(int i=1; i<=y; i++)
            m*=(1.0+r/100.0);
            printf("%.lf\n",floor(m));
    }
    return 0;
}
