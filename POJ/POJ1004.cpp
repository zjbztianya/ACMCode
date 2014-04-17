#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double gz;
    while(scanf("%lf",&gz)!=EOF)
    {
        double sum=gz;
        for(int i=0; i<11; i++)
        {
            scanf("%lf",&gz);
            sum+=gz;
        }
        printf("$%.2lf\n",sum/12.0);
    }
    return 0;
}
