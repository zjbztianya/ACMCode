class LittleElephantAndIntervalsDiv2
{
public:
    int getNumber(int M, vector <int> L, vector <int> R)
    {
        int len=L.size();
        int visit[105];
        memset(visit,0,sizeof(visit));
        for(int i=len-1; i>=0; i--)
            for(int j=L[i]; j<=R[i]; j++)
                if(!visit[j]) visit[j]=i+1;
        set<int>iset;
        for(int i=1; i<=M; i++)
            if(visit[i]) iset.insert(visit[i]);
        return 1<<(LL)iset.size();
    }


};
// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
