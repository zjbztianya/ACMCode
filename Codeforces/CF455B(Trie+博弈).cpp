/*************************************************************************
	> File Name: CF455B.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月15日 星期五 08时45分47秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define maxn 111111
char s[maxn];

struct Trie
{
    int ch[maxn][26];
    int win[maxn],lose[maxn];
    int sz;
    void clear()
    {
        sz=1;
        memset(ch[0],0,sizeof(ch[0]));
    }
    int idx(char c)
    {
        return c-'a';
    }
    void insert(char *s)
    {
        int n=strlen(s),u=0;
        for(int i=0; i<n; i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
    }
    void dfs(int u)
    {
        bool flag=false;
        for(int i=0; i<26; i++)
            if(ch[u][i])
            {
                flag=true;
                dfs(ch[u][i]);
                if(!win[ch[u][i]])  win[u]=1;
                if(!lose[ch[u][i]])  lose[u]=1;
            }
        if(!flag)
        {
            win[u]=0;
            lose[u]=1;
        }
    }
};
Trie trie;
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        trie.clear();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            trie.insert(s);
        }
        trie.dfs(0);
        if(trie.win[0]&&!trie.lose[0])
        {
            if(k&1) puts("First");
            else puts("Second");
        }
        else if(trie.win[0]&&trie.lose[0])  puts("First");
        else puts("Second");
    }
    return 0;
}

