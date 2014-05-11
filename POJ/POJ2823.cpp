#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1000005
int a[maxn],q[maxn];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        int head,tail;
        head=0,tail=-1;
        for(int i=0; i<k; i++)
        {
            while(head<=tail&&a[q[tail]]>a[i]) tail--;
            q[++tail]=i;
        }
        for(int i=k; i<n; i++)
        {
            printf("%d ",a[q[head]]);
            while(head<=tail&&q[head]<=(i-k)) head++;
            while(head<=tail&&a[q[tail]]>a[i]) tail--;
            q[++tail]=i;
        }
        printf("%d\n",a[q[head]]);
        head=0,tail=-1;
        for(int i=0; i<k; i++)
        {
            while(head<=tail&&a[q[tail]]<a[i]) tail--;
            q[++tail]=i;
        }
        for(int i=k; i<n; i++)
        {
            printf("%d ",a[q[head]]);
            while(head<=tail&&q[head]<=(i-k)) head++;
            while(head<=tail&&a[q[tail]]<a[i]) tail--;
            q[++tail]=i;
        }
        printf("%d\n",a[q[head]]);
    }
    return 0;
}
