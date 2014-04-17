class AlienAndGame
{
        public:
        int getNumber(vector <string> board)
        {
                int s=0;
                for(int i=0;i<board.size();i++)
                for(int j=0;j<board[i].size();j++)
                {
                    int w=10000;
                    for(int x=i;x>=0;x--)
                    {
                        int y=j-1,cnt=1;
                        while(y>=0&&board[x][y]==board[x][y+1])
                        {
                            y--;
                            cnt++;
                        }
                        w=min(w,cnt);
                        int p=min(w,i-x+1);
                        s=max(s,p*p);
                    }
                }
                return s;
        }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
