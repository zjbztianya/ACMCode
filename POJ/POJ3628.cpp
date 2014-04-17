#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int mins,n,h;
int height[20];
void dfs(int sum,int step)
{
    if(step>n||sum>=h)
    {
        if(sum>=h&&sum-h<mins) mins=sum-h;
        return;
    }
    dfs(sum+height[step],step+1);
    dfs(sum,step+1);
}
int main()
{
    scanf("%d%d",&n,&h);
    for(int i=1; i<=n; i++) scanf("%d",&height[i]);
    mins=INF;
    dfs(0,1);
    printf("%d\n",mins);
    return 0;
}
