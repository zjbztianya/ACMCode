#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
int main()
{
    LL x,y;
    int kase=0;
    while(cin>>x>>y)
    {
        LL ans=0;
        for(LL a=0;a<=1000;a++)
        for(LL b=0;b<=1000;b++)
        if(a>=x&&a<=y&&b>=x&&b<=y)
        {
               LL c=a*a*a+b*b*b;
               if(c%10==3)
               {
                      c/=10;
                      if(c>=x&&c<=y) ans++;
               }
        }
        cout<<"Case "<<++kase<<": "<<ans<<"\n";
    }
    return 0;
}
