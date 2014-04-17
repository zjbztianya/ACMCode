#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
int a[15];
int main(void)
{
    int sum,mins=INF,pos;
    string s;
    scanf("%d",&sum);
    for(int i=1; i<=9; i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<mins)
        {
            pos=i;
            mins=a[i];
        }
    }
    int len=sum/mins;
    sum-=len*mins;
    for(int i=0;i<len;i++)
    s+=pos+'0';
    for(int i=0;i<len;i++)
    {
        for(int j=9;j>=1;j--)
        if(sum+mins-a[j]>=0)
        {
            sum+=mins-a[j];
            s[i]=j+'0';
            break;
        }
    }
    if(!len) printf("-1\n");
    else
    cout<<s<<endl;
    return 0;
}

