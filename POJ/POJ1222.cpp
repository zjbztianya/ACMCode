#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 35
int A[MAXN][MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(A,0,sizeof(A));
        for(int i=0; i<30; i++) scanf("%d",&A[i][30]);
        for(int i=0; i<5; i++)
            for(int j=0; j<6; j++)
            {
                int t=i*6+j;
                A[t][t]=1;
                if(i>0) A[(i-1)*6+j][t]=1;


            }
    }
    return 0;
}
