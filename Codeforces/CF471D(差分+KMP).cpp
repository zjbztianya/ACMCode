#include<bits/stdc++.h>
using namespace std;
#define maxn 222222
typedef long long LL;
int f[maxn],a[maxn],b[maxn];
int n,m;
void getFail()
{
    int j;
    f[0]=j=-1;
    for(int i=1; i<m; i++)
    {
        while(j>=0&&b[j+1]!=b[i]) j=f[j];
        if(b[j+1]==b[i]) j++;
        f[i]=j;
    }
}
int find()
{
    int j=-1,ans=0;
    for(int i=0; i<n; i++)
    {
        while(j>=0&&b[j+1]!=a[i]) j=f[j];
        if(b[j+1]==a[i]) j++;
        if(j==m-1)
        {
            ans++;
            j=f[j];
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    if(m==1)
    {
        printf("%d\n",n);
    }
    else if(n<m)
    {
        printf("0\n");
    }
    else
    {
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        for(int i=0; i<m; i++) scanf("%d",&b[i]);
        for(int i=1; i<n; i++) a[i-1]=a[i]-a[i-1];
        for(int i=1; i<m; i++) b[i-1]=b[i]-b[i-1];
        n--;
        m--;
        getFail();
        printf("%d\n",find());
    }
    return 0;
}
