#define INF 0x3f3f3f3f
class TheShuttles
{
public:
    int getLeastCost(vector <int> cnt, int baseCost, int seatCost)
    {
        int m=-1;
        for(int i=0; i<cnt.size(); i++)
            m=max(m,cnt[i]);
        int ans=INF;
        for(int i=1; i<=m; i++)
        {
            int sum=0;
            for(int j=0; j<cnt.size(); j++)
                sum+=(cnt[j]+i-1)/i;
            ans=min(ans,(baseCost+i*seatCost)*sum);
        }
        return ans;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
