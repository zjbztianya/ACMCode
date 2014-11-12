#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 5555
int flag[66];
int ans[maxn],s[maxn];
struct node
{
    int id,p;
};
node a[maxn];
int getsum(int n)
{
    int ret=0;
    while(n)
    {
        ret+=n%10;
        n/=10;
    }
    return ret;
}
bool cmp(node a,node b)
{
    return a.p<b.p;
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0; i<k; i++)
        {
            scanf("%d",&a[i].p);
            a[i].id=i;
        }
        sort(a,a+k,cmp);
        memset(flag,false,sizeof(flag));
        int cnt=0,len=0;
        for(int i=1; i<=n; i++)
        {
            if(!flag[i%64])
            {
                ++cnt;
                while(cnt==a[len].p&&len<k)
                {
                    ans[len++]=i;
                }
            }
            int num=i+getsum(i);
            flag[i%64]=false;
            flag[num%64]=true;
        }
        printf("%d\n",cnt);
        for(int i=0; i<k; i++) s[a[i].id]=ans[i];
        for(int i=0; i<k-1; i++) printf("%d ",s[i]);
        printf("%d\n",s[k-1]);
    }
    return 0;
}
