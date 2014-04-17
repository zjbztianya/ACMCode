#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
string s;
int f[25][25];
int dx[4]= {-2,2,2,-2};
int dy[4]= {2,2,-2,-2};
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        memset(f,-1,sizeof(f));
        int x1,y1,x2,y2;
        bool  first=true;
        for(int i=0; i<8; i++)
        {
            cin>>s;
            for(int j=0; j<8; j++)
                if(s[j]=='K')
                {
                    if(first)
                    {
                        x1=i+1;
                        y1=j+1;
                        first=false;
                    }
                    else
                    {
                        x2=i+1;
                        y2=j+1;
                    }
                    f[i+1][j+1]=2;
                }
                else if(s[j]=='.')
                    f[i+1][j+1]=1;
                else
                    f[i+1][j+1]=0;
        }
        bool flag=false;
        if(gcd(abs(x1-x2),abs(y1-y2))==1)
        {
              printf("NO\n");
              continue;
        }
        for(int i=1; i<=8; i++)
            for(int j=1; j<=8; j++)
            {
                if(gcd(abs(x1-i),abs(x2-i))==2&&gcd(abs(y1-j),abs(y2-j))==2&&f[i][j]==1)
                {
                    flag=true;
                    break;
                }
            }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}




