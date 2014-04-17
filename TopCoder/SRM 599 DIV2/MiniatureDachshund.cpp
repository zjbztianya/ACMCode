class MiniatureDachshund
{
public:
    int maxMikan(vector <int> mikan, int weight)
    {
        int dp[5005];
        memset(dp,0,sizeof(dp));
        int v=5000-weight;
        for(size_t i=0; i<mikan.size(); i++)
            for(int j=v; j>=mikan[i]; j--)
                dp[j]=max(dp[j],dp[j-mikan[i]]+1);
        return dp[v];
    }
};


