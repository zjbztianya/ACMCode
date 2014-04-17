class LittleElephantAndDouble
{
        public:
        string getAnswer(vector <int> A)
        {
               for(int i=0;i<A.size();i++)
               {
                   while(A[i]%2==0)
                   A[i]/=2;
               }
               for(int i=1;i<A.size();i++)
               if(A[i]!=A[0]) return "NO";
               return "YES";
        }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
