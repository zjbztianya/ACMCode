#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
#define MAXN 40005
int dp[MAXN];
int a[MAXN];
vector<int>ivec;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)   scanf("%d",&a[i]);
        ivec.clear();
        for(int i=1; i<=n; i++)
            if(ivec.empty()) ivec.push_back(a[i]);
            else
            {
                vector<int>::iterator pos=lower_bound(ivec.begin(),ivec.end(),a[i]);
                if(pos==ivec.end()) ivec.push_back(a[i]);
                else
                *pos=a[i];
            }
        printf("%d\n",ivec.size());
    }
    return 0;
}
