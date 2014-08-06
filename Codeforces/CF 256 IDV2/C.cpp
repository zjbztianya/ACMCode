#include <bits/stdc++.h>
using namespace std;
#define maxn 5005
#define INF 0x3f3f3f3f
int a[maxn];
int dfs(int x,int y,int dec)
{
    if(x>y) return 0;
    if(x == y) return a[x] > dec ;
    int pos=min_element(a+x,a+y+1)-a;
    int ret=0;
    ret+=dfs(x,pos-1,a[pos]);
    ret+=dfs(pos+1,y,a[pos]);
    ret+=a[pos]-dec;
    return min(ret,y-x+1);
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        printf("%d\n",dfs(0,n-1,0));
    }
    return 0;
}