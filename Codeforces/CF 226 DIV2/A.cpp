#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    int a,ans=0;
    cin>>a;
    for(int i=2; i<=n; i++)
    {
        int b;
        cin>>b;
        ans=max(ans,a-b-c);
        a=b;
    }
    cout<<ans<<endl;
    return 0;
}

