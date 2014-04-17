#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAXN 5555
string s;
int main()
{
    cin>>s;
    int ans=0,pos;
    while((pos=s.find("bear"))!=-1)
    {
        ans+=(pos+1)*(s.size()-pos-3);
        s.erase(s.begin(),s.begin()+pos+1);
    }
    cout<<ans<<endl;
    return 0;
}
