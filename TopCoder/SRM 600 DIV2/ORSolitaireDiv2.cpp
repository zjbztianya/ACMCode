#define INF 0x3f3f3f3f
class ORSolitaireDiv2
{
public:
    int getMinimum(vector <int> numbers, int goal)
    {
        int ans=INF;
        int cnt[40];
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<numbers.size(); i++)
        {
            if((numbers[i]|goal)!=goal) continue;
            for(int j=0; j<30; j++)
                if(numbers[i]&(1<<j))cnt[j]++;
        }
        for(int i=0; i<30; i++)if(goal&(1<<i)) ans=min(ans,cnt[i]);
        return ans;
    }
};
