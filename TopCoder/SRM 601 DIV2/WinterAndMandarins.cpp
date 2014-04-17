class WinterAndMandarins
{
        public:
        int getNumber(vector <int> bags, int k)
        {
               sort(bags.begin(),bags.end());
               int ans=INF;
               for(int i=0;i<bags.size()&&i+k-1<bags.size();i++)
               ans=min(ans,bags[i+k-1]-bags[i]);
               return ans;
        }
};
