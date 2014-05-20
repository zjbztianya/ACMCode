#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 100005
#define INF 0x3f3f3f3f
#define KT (ch[ ch[rt][1] ][0])
struct SplayTree
{
    int val[maxn];
    int ch[maxn][2];
    int pre[maxn];
    int rt,tp1,tp2;
    int ss[maxn],que[maxn];
    inline void Rotate(int x,int f)
    {
        int y=pre[x];
        ch[y][!f]=ch[x][f];
        pre[ch[x][f]]=y;
        pre[x]=pre[y];
        if(pre[y]) ch[pre[y]][ch[pre[y]][1]==y]=x;
        ch[x][f]=y;
        pre[y]=x;
    }
    inline void Splay(int x,int goal)
    {
        while(pre[x]!=goal)
        {
            if(pre[pre[x]]==goal)
                Rotate(x,ch[pre[x]][0]==x);
            else
            {
                int y=pre[x],z=pre[y];
                int f=(ch[z][0]==y);
                if(ch[y][f]==x)
                {
                    Rotate(x,!f),Rotate(x,f);
                }
                else
                {
                    Rotate(y,f),Rotate(x,f);
                }
            }
        }
        if(goal==0) rt=x;
    }
    inline int insert(int k)
    {
        int x=rt;
        while(ch[x][val[x]<k])
        {
            if(val[x]==k)
            {
                Splay(x,0);
                return 0;
            }
            x=ch[x][val[x]<k];
        }
        NewNode(ch[x][val[x]<k],x,k);
        Splay(ch[x][val[x]<k],0);
        return 1;
    }
    inline void NewNode(int &x,int f,int c)
    {
        if(tp2) x=ss[--tp2];
        else x=++tp1;
        ch[x][0]=ch[x][1]=0;
        pre[x]=f;
        val[x]=c;
    }
    inline void init()
    {
        ch[0][0]=ch[1][0]=pre[0];
        rt=tp1=tp2=0;
        NewNode(rt,0,-1);
        NewNode(ch[rt][1],rt,-1);
        pre[tp1]=rt;
    }
    int get_pre()
    {
        int x=ch[rt][0];
        if(x==0) return -INF;
        while(ch[x][1]) x=ch[x][1];
        return val[x];
    }
    int get_suc()
    {
        int x=ch[rt][1];
        if(x==0) return INF;
        while(ch[x][0]) x=ch[x][0];
        return val[x];
    }
};
SplayTree spt;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int ans=0;
        spt.init();
        for(int i=0; i<n; i++)
        {
            int num;
            if(scanf("%d",&num)==EOF) num=0;
            if(i==0)
            {
                ans+=num;
                spt.NewNode(spt.rt,0,num);
                continue;
            }
            if(spt.insert(num)==0) continue;
            int a=num-spt.get_pre();
            int b=spt.get_suc()-num;
            ans+=min(a,b);
        }
        printf("%d\n",ans);
    }
    return 0;
}
