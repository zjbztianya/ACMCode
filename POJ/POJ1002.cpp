#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
char s[MAXN][50];
map<string,int>ms;
vector< pair<string,int> >ivec;
struct node
{
    char s[50];
    int cnt;
};
node a[MAXN];
const int has[26]= {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
void solve(char *str,int k)
{
    char ss[50];
    int len=strlen(str),cnt=0;
    for(int i=0; i<len; i++)
        if(str[i]!='-')
        {
            if(isupper(str[i]))
                ss[cnt++]=has[str[i]-'A']+'0';
            else
                ss[cnt++]=str[i];
        }
    ss[cnt]='\0';
    strcpy(s[k],ss);
    ms[string(ss)]++;
}
bool cmp(const node x,const node y)
{
    string a,b;
    a=string(x.s);
    b=string(y.s);
    return a<b;

}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        ms.clear();
        ivec.clear();
        for(int i=0; i<n; i++)
        {
            char str[50];
            scanf("%s",str);
            solve(str,i);
        }
        int t=0;
        for(int i=0; i<n; i++)
            if(ms[string(s[i])]>1)
            {
                strcpy(a[t].s,s[i]);
                a[t++].cnt=ms[string(s[i])];
                ms[string(s[i])]=0;
            }
        sort(a,a+t,cmp);
        bool flag=true;
        for(int i=0; i<t; i++)
        {
            flag=false;
            int len=strlen(a[i].s);
            for(int j=0; j<len; j++)
            {
                printf("%c",a[i].s[j]);
                if(j==2) printf("-");
            }
            printf(" %d\n",a[i].cnt);
        }
        if(flag) printf("No duplicates.\n");
    }
    return 0;
}
