#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define  INF 0x3f3f3f3f
#define  maxn 1111111
typedef long long LL;
int wa[maxn], wb[maxn],wv[maxn],ws[maxn],r[maxn],sa[maxn];
char str[maxn];
LL sum[maxn],tot;
int ll, rr;
int cmp(int *r, int a, int b, int l)
{
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int *r, int *sa, int n, int m)
{
    int i, j, p, *x = wa, *y = wb, *t;
    for (i = 0; i < m; i++) ws[i]=0;
    for (i = 0; i < n; i++) ws[x[i] = r[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--ws[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p)
    {
        for (p = 0, i = n - j; i < n; i++) y[p++] = i;
        for (i = 0; i < n; i++) if (sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; i++) wv[i] = x[y[i]];
        for (i = 0; i < m; i++) ws[i] = 0;
        for (i = 0; i < n; i++) ws[wv[i]]++;
        for (i = 1; i < m; i++) ws[i] += ws[i - 1];
        for (i = n - 1; i >= 0; i--) sa[--ws[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}
int rank[maxn], height[maxn];
void calheight(int *r, int *sa, int n)
{
    int i, j, k = 0;
    for (i = 1; i <= n; i++) rank[sa[i]] = i;
    for (i = 0; i < n; height[rank[i++]] = k)
        for (k ? k-- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k++);
    return;
}
int RMQ[maxn];
int mm[maxn];
int best[maxn][20],d[maxn][20];
void RMQ_init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        d[i][0] = height[i];
        best[i][0] = sa[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
            best[i][j] = min(best[i][j - 1], best[i + (1 << (j - 1))][j - 1]);
        }
}
int askRMQ(int L, int R)
{
    if (L>R) swap(L, R);
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1) k++;
    return min(d[L][k], d[R - (1 << k) + 1][k]);
}
int query(int L, int R)
{
    if (L > R) swap(L, R);
    int k = 0;
    while ((1 << (k + 1)) <= R - L + 1) k++;
    return min(best[L][k], best[R - (1 << k) + 1][k]);
}
int lcp(int a, int b,int n)
{
    int t;
    a = rank[a];
    b = rank[b];
    if(a==b) return n-sa[a];
    if (a>b)
    {
        t = a;
        a = b;
        b = t;
    }
    return askRMQ(a+1,b);
}
void Bin(LL k,int n)
{
    int pos = 0;
    int st = 1, ed = n;
    while (st <= ed)
    {
        int mid = (st + ed) >> 1;
        if (sum[mid] >= k)
        {
            pos = mid;
            ed = mid - 1;
        }
        else st = mid + 1;
    }
    int len = k - sum[pos - 1] + height[pos];
    st = pos, ed = n;
    int L, R;
    L = pos;
    R = pos;
    while (st<=ed)
    {
        int mid = (st + ed) >> 1;
        if (lcp(sa[pos], sa[mid],n) >= len)
        {
            R = mid;
            st = mid + 1;
        }
        else
        {
            ed = mid - 1;
        }
    }
    ll = query(L, R)+1;
    rr = ll + len - 1;
    printf("%d %d\n",ll,rr);
}
int main()
{
    while (scanf("%s",str)!=EOF)
    {
        int n = strlen(str);
        for (int i = 0; i < n; i++) r[i] = str[i];
        r[n] = 0;
        da(r, sa, n+1, 256);
        calheight(r, sa, n);
        RMQ_init(n);
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            tot += n - sa[i] - height[i];
            sum[i] = sum[i - 1] + n - sa[i] - height[i];
        }
        int Q;
        scanf("%d", &Q);
        ll= rr = 0;
        while (Q--)
        {
            LL k,v;
            scanf("%I64d", &v);
            k = (v^ll^rr) + 1;
            if (k > tot)
            {
                ll = rr = 0;
                printf("0 0\n");
                continue;
            }
            Bin(k,n);
        }
    }
    return 0;
}

