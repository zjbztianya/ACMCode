#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct node
{
    string s;
    int cnt;
};
node a[155];
void hehe(int t,string s)
{
    int cnt=0,len=s.length();
    for(int i=0; i<len-1; i++)
        for(int j=i+1; j<len; j++)
            if(s[i]>s[j]) cnt++;
    a[t].cnt=cnt;
}
bool cmp(const node x,const node y)
{
      return x.cnt<y.cnt;
}
int main()
{
    int n,m;
    while(cin>>m>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>a[i].s;
            hehe(i,a[i].s);
        }
        stable_sort(a,a+n,cmp);
        for(int i=0;i<n;i++)
        cout<<a[i].s<<"\n";
    }
    return 0;
}
