bool visit[15][15];
bool check(int n,int m)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visit[i][j])
            {
                return false;
            }
    return true;
}
class FoxAndClassroom
{
public:
    string ableTo(int n, int m)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                memset(visit,false,sizeof(visit));
                int x,y;
                x=i,y=j;
                while(!visit[x][y])
                {
                    visit[x][y]=true;
                    x=(x+1)%n;
                    y=(y+1)%m;
                }
                if(check(n,m)) return "Possible";
            }
        return "Impossible";
    }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
