#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c;
int main()
{
    int d,n;
    bool flag=false;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&d);
        if(d==25) a++;
        else if(d==50)
        {
            if(a>0)
            {
                b++;
                a--;
            }
            else
            {
                flag=true;
                break;
            }
        }
        else
        {
            if(a>=3||(a>=1&&b>=1))
            {
                if(a>=1&&b>=1)
                {
                    a--;
                    b--;
                    c++;
                }
                else
                {
                    a-=3;
                    c++;
                }
            }
            else
            {
                flag=true;
                break;
            }
        }
    }
    if(flag) printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
