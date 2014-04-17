#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 1000005
char s[MAXN];
int f[MAXN];
void getfail(char *p,int len)
{
    int j;
    f[0]=j=-1;
    for(int i=1; i<len; i++)
    {
        while(j>=0&&p[j+1]!=p[i]) j=f[j];
        if(p[j+1]==p[i]) j++;
        f[i]=j;
    }
}
int find(int len)
{
    int x=strlen(s);
    int j=-1;
    for(int i=len-1; i<x-len; i++)
    {
        while(j>=0&&s[j+1]!=s[i]) j=f[j];
        if(s[j+1]==s[i]) j++;
        if(j+1==len) return len;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int pp=-1;
        scanf("%s",s);
        if(strlen(s)<3) printf("0\n");
        else
        {
            getfail(s,strlen(s));
            int j=strlen(s)-1;
            while(f[j]>=0)
            {
                if(f[j]+1>pp)
                {
                    int t=find(f[j]+1);
                    if(t>pp)
                    {
                        pp=t;
                        break;
                    }
                }
                j=f[j];
            }
            if(pp!=-1)
                printf("%d\n",pp);
            else
                printf("0\n");
        }
    }
    return 0;
}
