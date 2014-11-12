#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
#define maxn 1111
int n;
struct node
{
    int op,x;
};
node a[maxn];
int stack_go()
{
    stack<int>st;
    for(int i=0; i<n; i++)
    {
        if(a[i].op==1)
        {
            st.push(a[i].x);
        }
        else
        {
            if(!st.empty())
            {
                if(st.top()!=a[i].x) return 0;
                st.pop();
            }
            else return 0;
        }
    }
    return 1;
}
int queue_go()
{
    queue<int>que;
    for(int i=0; i<n; i++)
    {
        if(a[i].op==1)
        {
            que.push(a[i].x);
        }
        else
        {
            if(!que.empty())
            {
                if(que.front()!=a[i].x) return 0;
                que.pop();
            }
            else return 0;
        }
    }
    return 1;
}
int priority_queue_qo()
{
    priority_queue<int> que;
    for(int i=0; i<n; i++)
    {
        if(a[i].op==1)
        {
            que.push(a[i].x);
        }
        else
        {
            if(!que.empty())
            {
                if(que.top()!=a[i].x) return 0;
                que.pop();
            }
            else return 0;
        }
    }
    return 1;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++) scanf("%d%d",&a[i].op,&a[i].x);
        int cnt=0,sa,sb,sc;
        sa=sb=sc=0;
        sa=stack_go();
        sb=queue_go();
        sc=priority_queue_qo();
        cnt=sa+sb+sc;
        if(cnt==0)
        {
            puts("impossible");
        }
        else if(cnt>1)
        {
            puts("not sure");
        }
        else
        {
            if(sa==1) puts("stack");
            else if(sb==1) puts("queue");
            else puts("priority queue");
        }

    }
    return 0;
}
