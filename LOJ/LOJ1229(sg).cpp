#include <bits/stdc++.h>
using namespace std;
#define maxn 222
int sg[maxn];
vector<int>pos;
int SG(int x)
{
    int &s=sg[x];
    if(~s) return sg[x];
    bool vis[maxn]= {false};
    if(x-3>=0) vis[SG(x-3)]=true;
    if(x-4>=0) vis[SG(x-4)]=true;
    if(x-5>=0) vis[SG(x-5)]=true;
    for(int i=6; i<=x; i++)
        vis[SG(x-i)^SG(i-5)]=true;
    for(int i=0;; i++)
    {
        if(!vis[i])
        {
            s=i;
            break;
        }
    }
    return s;
}
int winning(char *s)
{
    int len=strlen(s);
    for(int i=0; i<len-2; i++) if(s[i]=='X'&&s[i+1]=='X'&&s[i+2]=='X') return 0;
    for(int i=0; i<len-1; i++) if(s[i]=='X'&&s[i+1]=='X') return 1;
    for(int i=0; i<len-2; i++) if(s[i]=='X'&&s[i+2]=='X') return 1;
    bool fg[maxn];
    memset(fg,true,sizeof(fg));
    for(int i=0; i<len; i++)
    {
        if(s[i]=='X')
        {
            for(int d=-2; d<=2; d++)
            {
                int x=d+i;
                if(x>=0&&x<len) fg[x]=false;
            }
        }
    }

    int st=-1,ret=0;
    fg[len]=false;
    for(int i=0; i<=len; i++)
    {
        if(st==-1&&fg[i]) st=i;
        if(st>=0&&!fg[i]) ret^=sg[i-st];
        if(!fg[i]) st=-1;
    }
    return ret==0?0:1;
}
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    memset(sg,-1,sizeof(sg));
    sg[0]=0;
    sg[1]=sg[2]=sg[3]=1;
    for(int i=4; i<=200; i++) SG(i);
    while(T--)
    {
        char s[maxn],str[maxn];
        pos.clear();
        scanf("%s",s);
        printf("Case %d: ",++kase);
        if(!winning(s)) printf("0\n");
        else
        {
            int len=strlen(s);
            for(int i=0; i<len; i++)
            {
                if(s[i]=='.')
                {
                    strcpy(str,s);
                    str[i]='X';
                    if(!winning(str)) pos.push_back(i+1);
                }
            }
            printf("%d",pos[0]);
            for(int i=1; i<pos.size(); i++) printf(" %d",pos[i]);
            printf("\n");
        }

    }
    return 0;
}
