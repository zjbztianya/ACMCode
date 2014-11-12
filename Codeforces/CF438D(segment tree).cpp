#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define  maxn 111111
#define  INF 0x3f3f3f3f
#define lson l,m,s<<1
#define rson m+1,r,s<<1|1
typedef long long LL;
LL sum[maxn << 2];
int num[maxn<<2];
void pushup(int s)
{
    sum[s] = sum[s << 1] + sum[s << 1 | 1];
    num[s]=max(num[s<<1],num[s<<1|1]);
}
void build(int l, int r, int s)
{
    if (l == r)
    {
        scanf("%d", &num[s]);
        sum[s]=num[s];
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(s);
}
void update(int ql, int qr, int l, int r, int s, int x)
{
    if (l==r)
    {
        sum[s]=num[s]=num[s]%x;
        return;
    }
    if(x>num[s]) return;
    int m = (l + r) >> 1;
    if (ql <= m)update(ql, qr, lson, x);
    if (qr > m) update(ql, qr, rson, x);
    pushup(s);
}
void change(int p,int d,int l,int r,int s)
{
    if(l==r)
    {
        sum[s]=num[s]=d;
        return;
    }
    int m=(l+r)>>1;
    if(p<=m) change(p,d,lson);
    if(p>m) change(p,d,rson);
    pushup(s);
}
LL query(int ql, int qr, int l, int r, int s)
{
    if (ql <= l&&r <= qr)
    {
        return sum[s];
    }
    int m = (l + r) >> 1;
    LL ret = 0;
    if (ql <= m) ret += query(ql, qr, lson);
    if (qr > m) ret += query(ql, qr, rson);
    return ret;
}
int main()
{
    int m, n;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        memset(sum, 0, sizeof(sum));
        memset(num,0,sizeof(num));
        build(1, n, 1);
        int op, l, r, x, k;
        while (m--)
        {
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d%d", &l, &r);
                printf("%I64d\n", query(l, r, 1, n, 1));
            }
            else if (op == 2)
            {
                scanf("%d%d%d", &l, &r, &x);
                update(l, r, 1, n, 1, x);
            }
            else
            {
                scanf("%d%d", &k, &x);
                change(k, x, 1, n, 1);
            }
        }
    }
    return 0;
}
