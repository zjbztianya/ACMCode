class ErasingCharacters
{
public:
    string simulate(string s)
    {
        if(s.size()<=1) return s;
        int i=1;
        while(i<s.size())
        {
            int i=1;
            while(i<s.size()&&s[i]!=s[i-1]) i++;
            if(i>=s.size()) break;
            s.erase(s.begin()+i-1,s.begin()+i+1);
        }
        return s;
    }
};
