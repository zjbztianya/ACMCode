#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define maxn 222222
queue<int>que;
int dis[maxn];
bool vis[maxn];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        while(!que.empty())  que.pop();
        memset(dis,0,sizeof(dis));
        memset(vis,false,sizeof(vis));
        if(n>=m)
        {
            printf("%d\n",n-m);
            continue;
        }
        que.push(n);
        vis[n]=true;
        dis[n]=0;
        while(!que.empty())
        {
            int h=que.front();
            if(h==m)
            {
                printf("%d\n",dis[m]);
                break;
            }
            if(h+1<=100000&&!vis[h+1])
            {
                que.push(h+1);
                dis[h+1]=dis[h]+1;
                vis[h+1]=true;
            }
            if(h-1>=0&&!vis[h-1])
            {
                que.push(h-1);
                dis[h-1]=dis[h]+1;
                vis[h-1]=true;
            }
            if(h*2<=100000&&!vis[h*2])
            {
                que.push(h*2);
                dis[h*2]=dis[h]+1;
                vis[h*2]=true;
            }
            que.pop();
        }
    }
    return 0;
}

