#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <deque>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 111111
typedef long long LL;
pair<int, int>mp[26];
stack< pair<int,int> >st;
int main()
{
    int n;
    while (cin>>n)
    {
        for (int i = 0; i < n; i++)
        {
            string s;
            int a, b;
            cin >> s >> a >> b;
            mp[s[0]-'A']=make_pair(a, b);
        }
        string s;
        while (cin >> s)
        {
            while (!st.empty()) st.pop();
            if (s.size() == 1)
            {
                cout << 0 << endl;
                continue;
            }
            LL ans = 0;
            bool flag = true;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == '(') continue;
                if (s[i] == ')')
                {
                    pair<int,int> a, b;
                    b = st.top();
                    st.pop();
                    a = st.top();
                    st.pop();
                    if (a.second!= b.first)
                    {
                        flag = false;
                        printf("error\n");
                        break;
                    }
                    ans += a.first*a.second*b.second;
                    st.push(make_pair(a.first,b.second));
                }
                else st.push(make_pair(mp[s[i]-'A'].first,mp[s[i]-'A'].second));
            }
            if (flag) printf("%I64d\n", ans);
        }
    }
    return 0;
}
