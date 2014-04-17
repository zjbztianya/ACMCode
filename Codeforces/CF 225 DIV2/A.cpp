#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define  MAXN 1005
bool visit[MAXN][MAXN];
int main()
{
    int n,cnt=0;
    memset(visit,false,sizeof(visit));
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(!visit[i][j-1]&&!visit[i-1][j])
            {
                visit[i][j]=true;
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(visit[i][j])
                printf("C");
            else
                printf(".");
        }
        printf("\n");
    }
    return 0;
}
