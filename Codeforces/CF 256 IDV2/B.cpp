#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int a[30],b[30];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0; i<s1.size(); i++) a[s1[i]-'a']++;
        for(int i=0; i<s2.size(); i++) b[s2[i]-'a']++;
        for(int i=0; i<26; i++)
            if(b[i]!=0&&(a[i]==0||b[i]>a[i]))
            {
                puts("need tree");
                return 0;
            }
        int ato=0,ar=0;
        if(s1.size()>s2.size())
        {
            ato=1;
            int pos=0;
            bool flag=true;
            for(int i=0; i<s2.size(); i++)
            {
                int p=-1;
                for(int j=pos; j<s1.size(); j++) if(s2[i]==s1[j])
                    {
                        p=j;
                        break;
                    }
                if(p==-1)
                {
                    flag=false;
                    break;
                }
                pos=p+1;
            }
            if(!flag) ar=1;
        }
        else if(s1.size()<s2.size())
        {
            puts("need tree");
            return 0;
        }
        else ar=1;
        if(ar==1&&ato==1) puts("both");
        else if(ar==1) puts("array");
        else puts("automaton");
    }
}