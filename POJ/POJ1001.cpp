#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
#define MAXN 5000
int a[MAXN],b[MAXN],c[MAXN];
void multi(string s,int n,int p)
{
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    reverse(s.begin(),s.end());
    int lena,lenb;
    lena=lenb=s.size();
    p=p*n;
    for(size_t i=0; i<s.size(); i++)
    {
        a[i]=s[i]-'0';
        b[i]=s[i]-'0';
    }
    n--;
    while(n--)
    {
        for(int i=0; i<lena; i++)
            for(int j=0; j<lenb; j++)
            {
                c[i+j]+=a[i]*b[j];
                c[i+j+1]+=c[i+j]/10;
                c[i+j]%=10;
            }
        int len=lena+lenb;
        while(!c[len]) len--;
        len++;
        lenb=len;
        memcpy(b,c,sizeof(c));
        memset(c,0,sizeof(c));
    }
    reverse(b,b+lenb);
    //cout<<p<<endl;
    if(lenb==p)
    {
        printf(".");
        for(int i=0; i<lenb; i++)
            printf("%d",b[i]);
        printf("\n");

    }
    else if(lenb<p)
    {
        printf(".");
        for(int i=0; i<p-lenb; i++)
            printf("0");
        for(int i=0; i<lenb; i++)
            printf("%d",b[i]);
        printf("\n");
    }
    else
    {
        for(int i=0; i<lenb-p; i++)
            printf("%d",b[i]);
        if(p)printf(".");
        for(int i=lenb-p; i<lenb; i++)
            printf("%d",b[i]);
        printf("\n");
    }
}
int main()
{
    //freopen("test.txt","r",stdin);
    //freopen("a.txt","w",stdout);
    string s;
    int n;
    while(cin>>s>>n)
    {
        int p=0,index=-1;
        while(s[0]=='0') s.erase(s.begin());
        while(s[s.size()-1]=='0') s.erase(s.end()-1);
        for(size_t i=0; i<s.size(); i++)
            if(s[i]=='.')
            {
                p=s.size()-i-1;
                index=i;
                break;
            }
        if(index!=-1)s.erase(s.begin()+index);
        if(s.size()==0)
        {
            printf("0\n");
            continue;
        }
        if(s.size()==1&&s[0]=='1')
        {
            printf("1\n");
            continue;
        }
        //cout<<s<<endl;
        multi(s,n,p);
    }
    return 0;
}
