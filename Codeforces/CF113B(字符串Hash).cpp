#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int maxn=10000;
const int x=123; //hash�����Ĳ���
ULL H[maxn];//�ַ���hashֵ
ULL xp[maxn];//x��n����
void hash_init(char *s) //��ʼ��H(n),x^n
{
    int n=strlen(s);
    H[n]=0;
    for(int i=n-1; i>=0; i--) H[i]=H[i+1]*x+(s[i]); //����H(n)
    xp[0]=1;
    for(int i=1; i<=n; i++) xp[i]=xp[i-1]*x; //����X^n
}
ULL  Hash(int i,int L)//hash����.�������Ϊi,����ΪL��hashֵ
{
    return H[i]-H[i+L]*xp[L];
}
char s[maxn],a[maxn],b[maxn];
vector<ULL>vec;
int main()
{
    while(scanf("%s%s%s",s,a,b)!=EOF)
    {
        vec.clear();
        hash_init(s);
        int lena=strlen(a);
        int lenb=strlen(b);
        ULL aa,bb;
        aa=bb=0;
        int n=strlen(s);
        for(int i=lena-1; i>=0; i--) aa=aa*x+(a[i]);
        for(int i=lenb-1; i>=0; i--) bb=bb*x+(b[i]);
        // cout<<aa<<" "<<bb<<endl;
        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
            {
                if(j-i+1<lena||j-i+1<lenb) continue;
                ULL num=Hash(i,j-i+1);
                //cout<<num<<endl;
                if(Hash(i,lena)==aa&&Hash(j-lenb+1,lenb)==bb)
                {
                    vec.push_back(num);
                }
            }
        sort(vec.begin(),vec.end());
        int ans=unique(vec.begin(),vec.end())-vec.begin();
        printf("%d\n",ans);
    }
    return 0;
}
