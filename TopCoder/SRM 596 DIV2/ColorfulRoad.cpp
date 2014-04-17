// BEGIN CUT HERE

// END CUT HERE
#line 5 "ColorfulRoad.cpp"
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
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define INF 0x3f3f3f3f
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
int dp[20];
bool check(char a,char b)
{
    return (a=='R'&&b=='G')||(a=='G'&&b=='B')||(a=='B'&&b=='R');
}
class ColorfulRoad
{
public:
    int getMin(string road)
    {
        int i,j;
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        FOR(i,1,road.size()-1)
        REP(j,i)
        if(check(road[j],road[i]))
            dp[i]=min(dp[i],dp[j]+(i-j)*(i-j));
        return dp[road.size()-1]==INF?-1:dp[road.size()-1];
    }

// BEGIN CUT HERE
public:
    void run_test(int Case)
    {
        if ((Case == -1) || (Case == 0)) test_case_0();
        if ((Case == -1) || (Case == 1)) test_case_1();
        if ((Case == -1) || (Case == 2)) test_case_2();
        if ((Case == -1) || (Case == 3)) test_case_3();
        if ((Case == -1) || (Case == 4)) test_case_4();
        if ((Case == -1) || (Case == 5)) test_case_5();
    }
private:
    template <typename T> string print_array(const vector<T> &V)
    {
        ostringstream os;
        os << "{ ";
        for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\",";
        os << " }";
        return os.str();
    }
    void verify_case(int Case, const int &Expected, const int &Received)
    {
        cerr << "Test Case #" << Case << "...";
        if (Expected == Received) cerr << "PASSED" << endl;
        else
        {
            cerr << "FAILED" << endl;
            cerr << "\tExpected: \"" << Expected << '\"' << endl;
            cerr << "\tReceived: \"" << Received << '\"' << endl;
        }
    }
    void test_case_0()
    {
        string Arg0 = "RGGGB";
        int Arg1 = 8;
        verify_case(0, Arg1, getMin(Arg0));
    }
    void test_case_1()
    {
        string Arg0 = "RGBRGBRGB";
        int Arg1 = 8;
        verify_case(1, Arg1, getMin(Arg0));
    }
    void test_case_2()
    {
        string Arg0 = "RBBGGGRR";
        int Arg1 = -1;
        verify_case(2, Arg1, getMin(Arg0));
    }
    void test_case_3()
    {
        string Arg0 = "RBRRBGGGBBBBR";
        int Arg1 = 50;
        verify_case(3, Arg1, getMin(Arg0));
    }
    void test_case_4()
    {
        string Arg0 = "RG";
        int Arg1 = 1;
        verify_case(4, Arg1, getMin(Arg0));
    }
    void test_case_5()
    {
        string Arg0 = "RBRGBGBGGBGRGGG";
        int Arg1 = 52;
        verify_case(5, Arg1, getMin(Arg0));
    }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ColorfulRoad ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
