/*************************************************************************
	> File Name: LOJ1041.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月14日 星期四 19时30分24秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 111
int sg[maxn][3][3];
int SG(int x,int st,int ed)
{
    int &s=sg[x][st][ed];
    if(~s) return s;
    bool vis[maxn];
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=2; j++)
        {
            if(i==1&&st==j) continue;
            if(i==x&&ed==j) continue;
            int tmp=SG(i-1,st,j)^SG(x-i,j,ed);
            vis[tmp]=true;
        }
    }
    for(int i=0;; i++)
        if(!vis[i])
        {
            s=i;
            break;
        }
    return s;
}
int main()
{
    memset(sg,-1,sizeof(sg));
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        char s[maxn];
        scanf("%s",s);
        int len=0,n=strlen(s),st=0,ed=0,cnt=0;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='.') len++;
            else
            {
                cnt++;
                if(s[i]=='X') ed=1;
                else ed=2;
                ans^=SG(len,st,ed);
                st=ed;
                len=0;
            }
        }
        ans^=SG(len,st,0);
        printf("Case %d: ",++kase);
        if(cnt&1)
        {
            if(ans==0) puts("Yes");
            else puts("No");
        }
        else
        {
            if(ans) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

