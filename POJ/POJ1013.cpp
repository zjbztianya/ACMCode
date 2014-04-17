#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 26
int lt[26],rt[26];
bool flag[26];
string a[3],b[3],c[3];
int main()
{
    //freopen("hehe.txt","r",stdin);
   // freopen("he.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(flag,true,sizeof(flag));
        memset(lt,0,sizeof(lt));
        memset(rt,0,sizeof(rt));
        for(int i=0; i<3; i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            for(size_t j=0; j<a[i].size(); j++)
                flag[a[i][j]-'A']=false;
            for(size_t j=0; j<b[i].size(); j++)
                flag[b[i][j]-'A']=false;
        }
        int cnt=0;
        for(int i=0; i<3; i++)
        {
            if(c[i]=="even")
            {
                for(size_t j=0; j<a[i].size(); j++)
                    flag[a[i][j]-'A']=true;
                for(size_t j=0; j<b[i].size(); j++)
                    flag[b[i][j]-'A']=true;
                    cnt++;
            }
            else if(c[i]=="up")
            {
                for(size_t j=0; j<a[i].size(); j++)
                    rt[a[i][j]-'A']++;
                for(size_t j=0; j<b[i].size(); j++)
                    lt[b[i][j]-'A']++;
            }
            else
            {
                for(size_t j=0; j<a[i].size(); j++)
                    lt[a[i][j]-'A']++;
                for(size_t j=0; j<b[i].size(); j++)
                    rt[b[i][j]-'A']++;
            }
        }
        cnt=3-cnt;
        for(int i=0;i<26;i++)
        if(lt[i]&&rt[i]) flag[i]=true;
        for(int i=0;i<26;i++)
        if(!flag[i]&&(lt[i]==cnt||rt[i]==cnt))
        {
              printf("%c is the counterfeit coin and it is %s.\n",i+'A',lt[i]?"light":"heavy");
              break;
        }
    }
    return 0;
}


