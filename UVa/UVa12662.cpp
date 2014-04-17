#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 105
#define INF 0x3f3f3f3f
string s[MAXN];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1; i<=n; i++) cin>>s[i];
        int m;
        cin>>m;
        while(m--)
        {
            int x,y,pos;
            cin>>pos;
            if(s[pos][0]!='?') cout<<s[pos]<<endl;
            else
            {
                if(pos-1>=1) x=pos-1;
                else x=0;
                while(x>=1&&s[x][0]=='?') x--;
                if(pos+1<=n) y=pos+1;
                else y=n+1;
                while(y<=n&&s[y][0]=='?') y++;
                int disx=pos-x,disy=y-pos;
                if(x!=0&&y!=n+1)
                {
                    if(disx==disy) cout<<"middle of "+s[x]+" and "+s[y]<<"\n";
                    if(disx<disy)
                    {
                        for(int i=0; i<disx; i++) cout<<"right of ";
                        cout<<s[x]<<"\n";
                    }
                    if(disx>disy)
                    {
                        for(int i=0; i<disy; i++) cout<<"left of ";
                        cout<<s[y]<<"\n";

                    }
                }
                else if(x==0&&y!=n+1)
                {
                    for(int i=0; i<disy; i++) cout<<"left of ";
                    cout<<s[y]<<"\n";
                }
                else
                {
                    for(int i=0; i<disx; i++) cout<<"right of ";
                    cout<<s[x]<<"\n";

                }
            }
        }
    }
    return 0;
}
