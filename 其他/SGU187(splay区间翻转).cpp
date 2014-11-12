#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 150000
typedef long long LL;
int cnt;
int ans[maxn];
struct SplayTree
{
    int ch[maxn][2];
    int pre[maxn];
    int sz[maxn];
    int rev[maxn];
    int rt;
    void  Rotate(int x, int f)
    {
        int y = pre[x];
        pushdown(y);
        pushdown(x);
        ch[y][!f] = ch[x][f];
        if (ch[x][f]) pre[ch[x][f]] = y;
        pre[x] = pre[y];
        if (pre[y]) ch[pre[y]][ch[pre[y]][1] == y] = x;
        ch[x][f] = y;
        pre[y] = x;
        pushup(y);
    }
    void Splay(int x, int goal)
    {
        pushdown(x);
        while (pre[x] != goal)
        {
            if (pre[pre[x]] == goal)
            {
                Rotate(x, ch[pre[x]][0] == x);
            }
            else
            {
                int y = pre[x], z = pre[y];
                int f = (ch[z][0] == y);
                if (ch[y][f] == x)
                {
                    Rotate(x, !f), Rotate(x, f);
                }
                else
                {
                    Rotate(y, f), Rotate(x, f);
                }
            }
        }
        pushup(x);
        if (goal == 0) rt = x;
    }
    int get_kth(int k)
    {
        int x = rt;
        pushdown(x);
        for (;;)
        {
            int tmp = sz[ch[x][0]];
            if (tmp+1==k) break;
            if (k <= tmp) x = ch[x][0];
            else
            {
                k -= (tmp + 1);
                x = ch[x][1];
            }
            pushdown(x);
        }
        return x;
    }
    void RotateTo(int k, int goal)
    {
        int x = get_kth(k);
        Splay(x, goal);
    }
    void newnode(int &x, int f, int k)
    {
        x = k;
        ch[x][0] = ch[x][1] = rev[x]=0;
        pre[x] = f;
        sz[x] = 1;
    }
    void pushup(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
    }
    void go_rev(int x)
    {
        if (x)
        {
            swap(ch[x][0], ch[x][1]);
            rev[x] ^= 1;
        }
    }
    void pushdown(int x)
    {
        if (rev[x])
        {
            go_rev(ch[x][0]);
            go_rev(ch[x][1]);
            rev[x] ^= 1;
        }
    }
    void makeTree(int &x, int l, int r, int f)
    {
        if (l > r) return;
        int m = (l + r) >> 1;
        newnode(x, f, m);
        makeTree(ch[x][0], l, m - 1, x);
        makeTree(ch[x][1], m + 1, r, x);
        pushup(x);
    }
    void init(int n)
    {
        ch[0][0] = ch[0][1] = sz[0] = pre[0] = 0;
        rt = 0;
        newnode(rt, 0, n + 1);
        newnode(ch[rt][1], rt, n + 2);
        makeTree(ch[ch[rt][1]][0], 1, n, ch[rt][1]);
        pushup(ch[rt][1]);
        pushup(rt);
    }
    void flip(int x, int y)
    {
        RotateTo(x, 0);
        RotateTo(y + 2, rt);
        go_rev(ch[ch[rt][1]][0]);
    }
    void print(int x)
    {
        if (x)
        {
            pushdown(x);
            print(ch[x][0]);
            ans[cnt++] = x;
            print(ch[x][1]);
        }
    }
    void debug()
    {
        printf("%d\n", rt);
        Treaval(rt);
    }
    void Treaval(int x)
    {
        if (x)
        {
            Treaval(ch[x][0]);
            printf("���%2d:����� %2d �Ҷ��� %2d ����� %2d size = %2d \n", x, ch[x][0], ch[x][1], pre[x], sz[x]);
            Treaval(ch[x][1]);
        }
    }
};
SplayTree spt;
int main()
{
    int n, m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        spt.init(n);
        while (m--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            spt.flip(a, b);
        }
        spt.RotateTo(1, 0);
        spt.RotateTo(n + 2, spt.rt);
        cnt = 0;
        spt.print(spt.ch[spt.ch[spt.rt][1]][0]);
        for (int i = 0; i < cnt - 1; i++)printf("%d ", ans[i]);
        printf("%d\n", ans[cnt - 1]);
    }
    return 0;
}
