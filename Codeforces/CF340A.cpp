#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
      return b==0?a:gcd(b,a%b);
}
int main()
{
    long long x,y,a,b;
    cin>>x>>y>>a>>b;
    a--;
    long long d=x*y/gcd(x,y);
    long long l=a/d,r=b/d;
    cout<<r-l<<endl;
    return 0;
}
