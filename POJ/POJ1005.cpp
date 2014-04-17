#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)
int main()
{

    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        double x,y;
        scanf("%lf%lf",&x,&y);
        int n=ceil(PI*(x*x+y*y)/100.0);
        printf("Property %d: This property will begin eroding in year %d.\n",++kase,n);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
