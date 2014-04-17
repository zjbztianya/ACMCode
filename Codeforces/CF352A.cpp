#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n,ansa=0,ansb=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        if(a==0) ansa++;
        else     ansb++;
    }
    if(!ansa) printf("-1\n");
    else
    {
        int t=ansb/9;
        for(int i=0; i<t; i++)
            printf("555555555");
        if(t)
        {
            for(int i=0; i<ansa; i++)
                printf("0");
        }
        else
            printf("0");
        printf("\n");
    }
    return 0;
}
