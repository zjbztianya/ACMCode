class EllysNumberGuessing
{
public:
    int getNumber(vector <int> guesses, vector <int> answers)
    {
        map<int,int>ms;
        set<int>iset;
        for(int i=0; i<answers.size(); i++)
        {
            ms[guesses[i]+answers[i]]++;
            ms[guesses[i]-answers[i]]++;
            iset.insert(guesses[i]+answers[i]);
            iset.insert(guesses[i]-answers[i]);
        }
        int cnt=0,ans;
        for(set<int>::iterator iter=iset.begin(); iter!=iset.end(); ++iter)
        {
            int tmp=*iter;
            if(tmp>=1&&tmp<=1000000000&&ms[tmp]==answers.size())
            {
                cnt++;
                ans=tmp;
            }
        }
        if(cnt==0) return -2;
        if(cnt==2) return -1;
        return ans;
    }
};
