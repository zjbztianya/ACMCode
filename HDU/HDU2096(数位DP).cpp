#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 15
int dp[maxn][2],num[maxn];
int new_s(int s, int d)
{
    if (d == 6) return 1;
    else return 0;
}
int dfs(int i, int s, bool e) {
    if (i == -1) return 1;
    if (!e && ~dp[i][s]) return dp[i][s];
    int res = 0;
    int u = e ? num[i] : 9;
    for (int d = 0; d <= u; ++d)
    {
        if (d==4) continue;
        if (s&&d==2) continue;
        res += dfs(i - 1, new_s(s, d), e && d == u);
    }
    return e ? res : dp[i][s] = res;
}
int cal(int n)
{
    int cnt = 0;
    while (n)
    {
        num[cnt++] = n % 10;
        n /= 10;
    }
    return dfs(cnt - 1, 0,1);
}
int main()
{
    int l, r;
    memset(dp, -1, sizeof(dp));
    while (scanf("%d%d", &l, &r) != EOF&&l+r)
    {
        printf("%d\n", cal(r) - cal(l -1));
    }
    return 0;
}
