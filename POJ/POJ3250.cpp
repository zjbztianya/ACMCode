#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long LL;
stack<int>st;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(!st.empty()) st.pop();
        LL ans=0;
        for(int i=0; i<n; i++)
        {
            int h;
            scanf("%d",&h);
            while(!st.empty()&&st.top()<h) st.pop();
            ans+=st.size();
            st.push(h);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
