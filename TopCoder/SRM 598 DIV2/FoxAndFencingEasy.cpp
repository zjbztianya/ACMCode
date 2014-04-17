class FoxAndFencingEasy
{
        public:
        string WhoCanWin(int mov1, int mov2, int d)
        {
                if(d<=mov1) return "Ciel";
                if(mov1>2*mov2) return "Ciel";
                if(mov2>2*mov1) return "Liss";
                return "Draw";
        }
};
// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
