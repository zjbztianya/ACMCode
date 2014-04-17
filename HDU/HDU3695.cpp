#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int maxnode=500005;
const int sigma_size=26;
const int MAXN=5100005;
char T[MAXN],s[1005];
bool visit[maxnode];
int ans;
struct Triegragh
{
    int ch[maxnode][sigma_size];
    int fail[maxnode];
    int val[maxnode];
    int last[maxnode];
    int sz;
    void init()
    {
        memset(ch[0],0,sizeof(ch[0]));
        memset(visit,false,sizeof(visit));
        sz=1;
    }
    int idx(char c)
    {
        return c-'A';
    }
    void insert(char *s)
    {
        int u=0,n=strlen(s);
        for(int i=0; i<n; i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]++;
    }
    void getfail()
    {
        queue<int>q;
        fail[0]=0;
        for(int c=0; c<sigma_size; c++)
        {
            int u=ch[0][c];
            if(u)
            {
                fail[u]=0;
                q.push(u);
                last[u]=0;
            }
        }
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            for(int c=0; c<sigma_size; c++)
            {
                int u=ch[r][c];
                if(!u)
                {
                    ch[r][c]=ch[fail[r]][c];
                    continue;
                }
                fail[u]=ch[fail[r]][c];
                q.push(u);
                last[u]=val[fail[u]]?fail[u]:last[fail[u]];
            }
        }
    }
    void count(int j)
    {
        if(j)
        {
            if(!visit[j]) ans++;
            else return;
            visit[j]=true;
            count(last[j]);
        }
    }
    void find(char *T)
    {
        int n=strlen(T);
        int j=0;
        for(int i=0; i<n; i++)
        {
            int c=idx(T[i]);
            j=ch[j][c];
            if(val[j])
                count(j);
            else if(last[j]) count(last[j]);
        }
    }
};
Triegragh ac;
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int n;
        scanf("%d",&n);
        ac.init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            ac.insert(s);
        }
        ac.getfail();
        getchar();
        char c;
        int j=0;
        while(c=getchar(),c!='\n')
        {
            if(c=='[')
            {
                int m;
                scanf("%d",&m);
                c=getchar();
                for(int i=0; i<m; i++)
                    T[j++]=c;
                getchar();
            }
            else T[j++]=c;
        }
        T[j]='\0';
        ans=0;
        ac.find(T);
        reverse(T,T+strlen(T));
        ac.find(T);
        printf("%d\n",ans);
    }
    return 0;
}
