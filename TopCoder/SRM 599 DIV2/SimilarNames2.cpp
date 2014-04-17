#define MOD 1000000007
typedef long long LL;
LL dp[55][55],cnt[55];
class SimilarNames2
{
public:
    bool check(string a,string b)
    {
        if(a.size()<=b.size()&&b.substr(0,a.size())==a) return true;
        return false;
    }
    void Comb()
    {
        for(int i=0; i<=50; i++)
        {
            dp[i][0]=1,dp[i][i]=1;
            for(int j=1; j<i; j++)
                dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
        }
    }
    int count(vector <string> names, int L)
    {
        sort(names.begin(),names.end());
        int len=names.size();
        memset(dp,0,sizeof(dp));
        for(int i=0; i<len; i++)
        {
            cnt[i]=1;
            for(int j=0; j<i; j++)
            {
                if(check(names[j],names[i]))
                    cnt[i]=max(cnt[i],cnt[j]+1);
            }
        }
        Comb();
        LL fac=1;
        for(LL i=1; i<=len-L; i++)
            fac=(fac*i)%MOD;
        int ans=0;
        for(int i=0; i<len; i++)
            if(cnt[i]>=L)
                ans=((LL)ans+dp[cnt[i]-1][L-1]*fac)%MOD;
        return ans;
    }
};
