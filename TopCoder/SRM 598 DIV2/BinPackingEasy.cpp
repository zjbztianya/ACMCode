class BinPackingEasy
{
public:
    int minBins(vector <int> item)
    {
        int len=item.size();
        sort(item.begin(),item.end());
        int i,j,ans=0;
        for(i=0,j=len-1; i<=j;)
        {
            if(item[i]+item[j]<=300&&j!=i)
            {
                ans++;
                i++;
                j--;
            }
            else
            {
                ans++;
                j--;
            }
        }
        return ans;
    }
};
