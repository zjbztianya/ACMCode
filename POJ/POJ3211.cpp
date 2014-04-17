#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
#define MAXN 1005
string s[MAXN];
int dp[MAXN];
struct node
{
    int tm,cr;
};
node a[MAXN];
bool cmp(node x,node y)
{
    return x.cr<y.cr;
}
int main()
{
    int m,n;
    while(cin>>m>>n&&m+n)
    {
        for(int i=0; i<m; i++) cin>>s[i];
        for(int i=0; i<n; i++)
        {
            string str;
            cin>>a[i].tm>>str;
            for(int j=0; j<m; j++)
                if(s[j]==str)
                {
                    a[i].cr=j;
                    break;
                }
        }
        sort(a,a+n,cmp);
        int ans=0,j=0;
        vector<int>ivec;
        for(int i=0; i<m; i++)
        {
            ivec.clear();
            memset(dp,0,sizeof(dp));
            int sum=0;
            while(j<n&&a[j].cr==i)
            {
                ivec.push_back(a[j].tm);
                sum+=a[j].tm;
                j++;
            }
            for(size_t k=0; k<ivec.size(); k++)
                for(int p=sum/2; p>=ivec[k]; p--)
                    dp[p]=max(dp[p],dp[p-ivec[k]]+ivec[k]);
            ans+=sum-dp[sum/2];
        }
        cout<<ans<<endl;
    }
    return 0;
}
