#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 1000005
struct que
{
    int id,num;
};
que q[maxn];
char s[30];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int head,tail,cnt=0,p=0;
        head=0,tail=-1;
        while(scanf("%s",s)!=EOF&&s[0]!='E')
        {
            if(s[0]=='C')
            {
                int d;
                scanf("%s%d",s,&d);
                while(head<=tail&&q[tail].num<d) tail--;
                q[++tail].num=d;
                q[tail].id=cnt++;
            }
            else if(s[0]=='G')
            {
                if(head<=tail&&q[head].id<=p) head++;
                p++;
            }
            else
            {
                if(head<=tail)
                    printf("%d\n",q[head].num);
                else printf("-1\n");
            }
        }
    }
    return 0;
}
