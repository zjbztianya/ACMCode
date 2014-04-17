class LittleElephantAndString
{
public:
    int getNumber(string A, string B)
    {
        int a[MAXN],b[MAXN],i,j,n=A.size();
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        REP(i,n) a[A[i]-'A']++;
        REP(i,n) b[B[i]-'A']++;
        FOR(i,0,26) if(a[i]!=b[i]) return -1;
        int cnt=0;
        i=j=n-1;
        while(i>=0)
        {
            if(A[i]==B[j])
            {
                while(A[i]==B[j]&&i>=0)
                {
                    i--;
                    j--;
                    cnt++;
                }
            }
            else  i--;
        }
        return n-cnt;
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
