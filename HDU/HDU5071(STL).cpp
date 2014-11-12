#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
#define maxn 1111111
#define MOD 1000000007
deque< pair<int,LL> >arr;
int tp;
void Add(int x)
{
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
        if(it->first==x)
        {
            puts("same priority.");
            return;
        }
    arr.push_back(make_pair(x,0));
    puts("success.");
}
void Close(int x)
{
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
        if(it->first==x)
        {
            if(tp==x) tp=0;
            printf("close %d with %I64d.\n",x,it->second);
            arr.erase(it);
            return;
        }
    puts("invalid priority.");
}
void Chat(int x)
{
    if(arr.size()==0)
    {
        puts("empty.");
        return;
    }
    if(tp)
    {
        for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
            if(it->first==tp)
            {
                it->second+=x;
                break;
            }
    }
    else arr.front().second+=x;
    puts("success.");
}
void Rotate(int x)
{
    if(arr.size()<x||x<1)
    {
        puts("out of range.");
        return;
    }
    int cnt=1;
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it,++cnt)
        if(cnt==x)
        {
            pair<int,LL>pa=*it;
            arr.erase(it);
            arr.push_front(pa);
            break;
        }
    puts("success.");
}
void Prior()
{
    if(arr.size()==0)
    {
        puts("empty.");
        return;
    }
    deque< pair<int,LL> >::iterator mx=arr.begin();
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
        if(mx->first<it->first) mx=it;
    pair<int,LL>pa=*mx;
    arr.erase(mx);
    arr.push_front(pa);
    puts("success.");
}
void Choose(int x)
{
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
        if(it->first==x)
        {
            pair<int,LL>pa=*it;
            arr.erase(it);
            arr.push_front(pa);
            puts("success.");
            return;
        }
    puts("invalid priority.");
}
void Top(int x)
{
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
        if(it->first==x)
        {
            tp=x;
            puts("success.");
            return;
        }
    puts("invalid priority.");
}
void Untop()
{
    if(!tp)
    {
        puts("no such person.");
        return;
    }
    tp=0;
    puts("success.");
}
void Bye()
{
    deque< pair<int,LL> >::iterator fuck=arr.end();
    if(tp)
    {
        for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
            if(it->first==tp&&it->second)
            {
                printf("Bye %d: %I64d\n",tp,it->second);
                arr.erase(it);
                break;
            }
    }
    for(deque< pair<int,LL> >::iterator it=arr.begin(); it!=arr.end(); ++it)
    if(it->second)
    {
        printf("Bye %d: %I64d\n",it->first,it->second);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        arr.clear();
        tp=0;
        for(int i=1; i<=n; i++)
        {
            printf("Operation #%d: ",i);
            char op[10];
            int x;
            scanf("%s",op);
            if(op[0]=='A')
            {
                scanf("%d",&x);
                Add(x);
            }
            else if(op[1]=='l')
            {
                scanf("%d",&x);
                Close(x);
            }
            else if(op[2]=='a')
            {
                scanf("%d",&x);
                Chat(x);
            }
            else if(op[0]=='R')
            {
                scanf("%d",&x);
                Rotate(x);
            }
            else if(op[0]=='P') Prior();
            else if(op[0]=='C')
            {
                scanf("%d",&x);
                Choose(x);
            }
            else if(op[0]=='T')
            {
                scanf("%d",&x);
                Top(x);
            }
            else Untop();
        }
        Bye();
    }
    return 0;
}
