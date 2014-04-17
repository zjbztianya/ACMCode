#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
    int n,ave,t;
    scanf("%d",&n);
    //ave=(1+n*n)*n/2;
    t=n/2;
    int l,r;
    l=1;
    r=n*n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=t; j++)
            printf(" %d %d",l++,r--);
        printf("\n");
    }
    return 0;
}
