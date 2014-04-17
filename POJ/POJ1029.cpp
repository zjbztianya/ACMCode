#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1005
bool visit[MAXN];
int lt[MAXN],rt[MAXN];
vector<int>ivec;
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(visit,false,sizeof(visit));
        memset(lt,0,sizeof(lt));
        memset(rt,0,sizeof(rt));
        while(k--)
        {
            ivec.clear();
            int m;
            char s[10];
            scanf("%d",&m);
            for(int i=0; i<2*m; i++)
            {
                int a;
                scanf("%d",&a);
                ivec.push_back(a);
            }
            scanf("%s",s);
            if(s[0]=='<'||s[0]=='>')
            {
                if(s[0]=='<')
                {
                    for(int i=0; i<m; i++) lt[ivec[i]]++;
                    for(int i=m; i<2*m; i++) rt[ivec[i]]++;
                }
                else
                {
                    for(int i=0; i<m; i++) rt[ivec[i]]++;
                    for(int i=m; i<2*m; i++) lt[ivec[i]]++;
                }
                sort(ivec.begin(),ivec.end());
                for(int i=1; i<=n; i++)
                    if(!visit[i])
                    {
                        vector<int>::iterator pos=lower_bound(ivec.begin(),ivec.end(),i);
                        if(pos==ivec.end()||i!=ivec[pos-ivec.begin()])
                            visit[i]=true;
                    }
            }
            else if(s[0]=='=')
            {
                for(vector<int>::iterator iter=ivec.begin(); iter!=ivec.end(); ++iter)
                    visit[*iter]=true;
            }
        }
        for(int i=1; i<=n; i++)
            if(lt[i]&&rt[i]) visit[i]=true;
        int cnt=0,ans;
        for(int i=1; i<=n; i++)
            if(!visit[i])
            {
                cnt++;
                ans=i;
            }
        if(cnt==1) printf("%d\n",ans);
        else   printf("0\n");
    }
    return 0;
}







