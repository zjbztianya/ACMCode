#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
string s[3]=
{
    ".*...*...*...*...*..",
    "***...*.***.*...***.",
    "***...*.***...*.***.",
};
string ss[15];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<5; i++) cin>>ss[i];
        for(int i=0; i<n; i++)
        {
            string t;
            for(int j=0; j<5; j++)
            {
                for(int k=i*4; k<=(i+1)*4-1; k++)
                    t+=ss[j][k];
            }
            if(t==s[0]) cout<<1;
            if(t==s[1]) cout<<2;
            if(t==s[2]) cout<<3;
        }
        cout<<"\n";
    }
    return 0;
}

