#line 5 "FoxAndSightseeing.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
class FoxAndSightseeing
{
        public:
        int getMin(vector <int> position)
        {
                int ans=INF;
                for(int i=1;i<position.size()-1;i++)
                {
                       int sum=0,pre=position[0];
                       for(int j=1;j<position.size();j++)
                       {
                              if(j==i) continue;
                              sum+=abs(position[j]-pre);
                              pre=position[j];
                       }
                       if(sum<ans) ans=sum;
                }
                return ans;
        }
};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
