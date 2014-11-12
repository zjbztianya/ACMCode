#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn=55555;
const int x=31; //hash函数的参数
ULL H[maxn];//字符串hash值
ULL xp[maxn];//x的n次幂
void hash_init(char *s) //初始化H(n),x^n
{
    int n=strlen(s);
    H[n]=0;
    for(int i=n-1; i>=0; i--) H[i]=H[i+1]*x+s[i]; //递推H(n)
    xp[0]=1;
    for(int i=1; i<=n; i++) xp[i]=xp[i-1]*x; //递推X^n
}
ULL  Hash(int i,int L)//hash函数.返回起点为i,长度为L的hash值
{
    return H[i]-H[i+L]*xp[L];
}
char s[maxn];
int main()
{
    int T,kase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        hash_init(s);
        int n=strlen(s);
        int l=0,r=n-1,pre=0,next=n-1;
        int ans=0;
        if(n&1)
        {
            while(l<r)
            {
                if(Hash(pre,l-pre+1)==Hash(r,next-r+1))
                {
                    //printf("%d %d\n",l,r);
                    ans+=2;
                    pre=l+1,next=r-1;
                }
                l++,r--;
            }
            ans++;
        }
        else
        {
            while(l<r)
            {
                if(Hash(pre,l-pre+1)==Hash(r,next-r+1))
                {
                    //printf("%d %d\n",l,r);
                    ans+=2;
                    pre=l+1,next=r-1;
                }
                l++,r--;
            }
            if(pre!=l||next!=r) ans++;
        }
        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
