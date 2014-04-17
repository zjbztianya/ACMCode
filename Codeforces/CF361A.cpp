#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int d=k/n,m=k%n+d;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            if(i==j)
                printf("%d ",m);
            else
                printf("%d ",d);
        printf("\n");
    }

    return 0;
}
