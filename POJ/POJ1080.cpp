#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f
int dp[MAXN][MAXN];
int value[5][5]=
{
    {5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,-INF}
};
int idx(char ch)
{
    int ans;
    switch(ch)
    {
       case 'A':ans=0;break;
       case 'C':ans=1;break;
       case 'G':ans=2;break;
       case 'T':ans=3;break;
       default:ans=4;break;
    };
    return ans;
}
int match(char ch1,char ch2)
{
    int x,y;
    x=idx(ch1);
    y=idx(ch2);
    return value[x][y];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int lena,lenb;
        char a[MAXN],b[MAXN];
        scanf("%d%s",&lena,a+1);
        scanf("%d%s",&lenb,b+1);
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=lena; i++) dp[i][0]=dp[i-1][0]+match(a[i],'-');
        for(int j=1; j<=lenb; j++) dp[0][j]=dp[0][j-1]+match('-',b[j]);
        for(int i=1; i<=lena; i++)
            for(int j=1; j<=lenb; j++)
            {
                dp[i][j]=max(dp[i-1][j]+match(a[i],'-'),dp[i][j-1]+match('-',b[j]));
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+match(a[i],b[j]));
            }
        printf("%d\n",dp[lena][lenb]);
    }
    return 0;
}

