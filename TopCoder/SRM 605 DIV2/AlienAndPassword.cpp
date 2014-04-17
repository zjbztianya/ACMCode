class AlienAndPassword
{
        public:
        int getNumber(string S)
        {
                map<string,int> mp;
                mp.clear();
                int cnt=0;
                for(int i=0;i<S.size();i++)
                {
                    string str=S;
                    str.erase(str.begin()+i);
                    if(!mp[str])
                    {
                        cnt++;
                        mp[str]++;
                    }
                }
                return cnt;
        }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
