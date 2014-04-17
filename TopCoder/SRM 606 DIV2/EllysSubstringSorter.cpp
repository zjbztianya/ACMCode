class EllysSubstringSorter
{
public:
    string getMin(string S, int L)
    {
        string str=S;
        for(int i=0; i<S.size()-L+1; i++)
        {
            string tmp=string(S.begin()+i,S.begin()+i+L);
            sort(tmp.begin(),tmp.end());
            string ss;
            ss+=string(S.begin(),S.begin()+i);
            ss+=tmp;
            if(i+L<S.size()) ss+=string(S.begin()+i+L,S.end());
            if(str>ss) str=ss;
        }
        return str;
    }
};
