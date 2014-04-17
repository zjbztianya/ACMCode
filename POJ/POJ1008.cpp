#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
const char s1[19][15]= {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
const char s2[20][15]= {"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main()
{
    int T;
    scanf("%d",&T);
    printf("%d\n",T);
    while(T--)
    {
        char month[15];
        int  day,year,n,d,y,m;
        scanf("%d.%s%d",&day,month,&year);
        for(int i=0; i<19; i++)
            if(!strcmp(month,s1[i]))
            {
                n=i;
                break;
            }
        y=(year*365+day+n*20)/260;
        m=(year*365+day+n*20)%20;
        d=(year*365+day+n*20)%13+1;
        printf("%d %s %d\n",d,s2[m],y);
    }
    return 0;
}
