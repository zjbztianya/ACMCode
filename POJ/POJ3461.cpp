#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
#define MAXN 10005
char T[MAXN*100],P[MAXN];
int f[MAXN];
void getFail()
{
    int m=strlen(P);
    f[0]=f[1]=0;
    for(int i=1; i<m; i++)
    {
        int j=f[i];
        while(j&&P[j]!=P[i]) j=f[j];
        f[i+1]=P[j]==P[i]?j+1:0;
    }
}
int find()
{
    int n=strlen(T),m=strlen(P);
    getFail();
    int j=0,ans=0;
    for(int i=0; i<n; i++)
    {
        while(j&&P[j]!=T[i]) j=f[j];
        if(P[j]==T[i]) j++;
        if(j==m) ans++;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",P,T);
        printf("%d\n",find());
    }
    return 0;
}
