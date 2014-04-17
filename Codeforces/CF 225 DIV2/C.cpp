#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    LL cnt=0,ans=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int  a;
        scanf("%d",&a);
        if(a) cnt++;
        else ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}
