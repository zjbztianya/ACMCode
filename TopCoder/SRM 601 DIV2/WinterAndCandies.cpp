class WinterAndCandies
{
        public:
        int getNumber(vector <int> type)
        {
            if(*min_element(type.begin(),type.end())!=1) return 0;
            int ans=0;
            int cnt[55],fac[55];
            memset(cnt,0,sizeof(cnt));
            for(int i=0;i<type.size();i++)
            cnt[type[i]]++;
            fac[0]=1;
            for(int i=1;i<=50;i++)
            {
                ans+=cnt[i]*fac[i-1];
                fac[i]=fac[i-1]*cnt[i];
            }
            return ans;
        }
};
