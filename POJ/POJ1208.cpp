#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 30
vector<int>ivec[MAXN];
char s1[MAXN],s2[MAXN];
int n;
int find(int x)
{
    int t;
    for(int i=0; i<n; i++)
    {
        vector<int>::iterator pos;
        for(pos=ivec[i].begin(); pos!=ivec[i].end(); ++pos)
            if(*pos==x) break;
        if(pos!=ivec[i].end())
        {
            t=i;
            break;
        }
    }
    return t;
}
void renew(int x,int j,vector<int>::iterator &pos)
{
    for(pos=ivec[j].begin(); pos!=ivec[j].end(); ++pos)
        if(*pos==x) break;
    for(vector<int>::iterator iter=pos+1; iter!=ivec[j].end(); ++iter)
        ivec[*iter].push_back(*iter);
    ivec[j].erase(pos+1,ivec[j].end());
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            ivec[i].clear();
            ivec[i].push_back(i);
        }
        while(scanf("%s",s1)!=EOF&&s1[0]!='q')
        {
            int a,b;
            vector<int>::iterator itera,iterb;
            scanf("%d%s%d",&a,s2,&b);
            int posa=find(a),posb=find(b);
            if((posa==posb)||(a==b)) continue;
            if(s1[0]=='m')
            {
                renew(a,posa,itera);
                if(s2[1]=='n')
                    renew(b,posb,iterb);
                ivec[posb].push_back(a);
                ivec[posa].erase(itera);
            }
            else
            {
                for(itera=ivec[posa].begin(); itera!=ivec[posa].end(); ++itera)
                    if(*itera==a )break;
                if(s2[0]=='n')
                    renew(b,posb,iterb);
                ivec[posb].insert(ivec[posb].end(),itera, ivec[posa].end());
                ivec[posa].erase(itera,ivec[posa].end());
            }
        }
        for(int i=0; i<n; i++)
        {
            printf("%d:",i);
            for(vector<int>::iterator iter = ivec[i].begin(); iter!=ivec[i].end(); ++iter)
                printf(" %d",*iter);
            printf("\n");
        }

    }
    return 0;
}





