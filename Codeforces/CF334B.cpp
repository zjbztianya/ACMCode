#include<iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <map>
#include <set>
using namespace std;
pair<int,int>a[10];
set<int>ia,ib;
int main()
{
    for(int i=0; i<8; i++)
    {
        scanf("%d%d",&a[i].first,&a[i].second);
        ia.insert(a[i].first);
        ib.insert(a[i].second);
    }
    if(ia.size()!=3||ib.size()!=3)
    {
        printf("ugly\n");
        return 0;
    }
    int i=0,j;
    bool cnt=true;
    bool flag[10];
    memset(flag,false,sizeof(flag));
    for(set<int>::iterator itera=ia.begin(); itera!=ia.end(); ++itera,++i)
    {
        j=0;
        for(set<int>::iterator iterb=ib.begin(); iterb!=ib.end(); ++iterb,++j)
        {
            if(i==1&&j==1) continue;
            bool fk=false;
            for(int k=0; k<8; k++)
                if(a[k].first==(*itera)&&a[k].second==(*iterb)&&!flag[k])
                {
                    flag[k]=true;
                    fk=true;
                    break;
                }
            if(!fk) cnt=false;
        }
    }
    if(cnt) printf("respectable\n");
    else
        printf("ugly\n");
    return 0;
}
