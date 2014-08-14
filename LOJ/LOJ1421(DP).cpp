/*************************************************************************
	> File Name: LOJ1421.cpp
	> Author: zjbztianya
	> Mail: spcjv5@gmail.com
	> Created Time: 2014年08月08日 星期五 11时50分56秒
 ************************************************************************/

#include<bits/stdc++.h>
#define maxn 111111
int dpa[maxn],dpb[maxn];
int a[maxn],num[maxn];
using namespace std;
int main()
{
    int  T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        memset(dpa,0,sizeof(dpa));
        memset(dpb,0,sizeof(dpb));
        int cnt=1;
        num[1]=a[1];
        for(int i=2; i<=n; i++)
        {
            if(a[i]>num[cnt])
            {
                dpa[i]=cnt+1;
                num[++cnt]=a[i];
            }
            else
            {
                int pos=lower_bound(num+1,num+cnt+1,a[i])-num;
                num[pos]=a[i];
                dpa[i]=cnt;
            }
        }
        cnt=1;
        num[1]=a[n];
        for(int i=n-1; i>=1; i--)
        {
            if(a[i]>num[cnt])
            {
                dpb[i]=cnt+1;
                num[++cnt]=a[i];
            }
            else
            {
                int pos=lower_bound(num+1,num+cnt+1,a[i])-num;
                num[pos]=a[i];
                dpb[i]=cnt;
            }
        }
        int ans=1;
        for(int i=1; i<n; i++) ans=max(ans,min(dpa[i],dpb[i])*2-1);
        printf("Case %d: %d\n",++kase,ans);
    }
}

