#include <cassert>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cstddef>
#include <cctype>
#include <cmath>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <list>
#include <string>
#include <functional>
#include <utility>
using namespace std;
typedef long long llint;
class EagleInZoo
{
public:
    double calc(vector <int> parent, int K);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.5; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,0,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 0.75; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,1,1,2,4,4,4,5,5,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; double Arg2 = 0.14595168754091617; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,1,2,3,2,1,1,7,0,9,10,11,12,13,14,15,16,17,18,14,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; double Arg2 = 0.3272154791654077; verify_case(4, Arg2, calc(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; double Arg2 = 0.0; verify_case(5, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};
vector <vector <int> > adj;
vector <vector <double> > comb;
vector <vector <double> > dp;
double dfs(int u, int k)
{
    if (dp[u][k] > -0.5)
    {
        return dp[u][k];
    }
    if (k <= 1)
    {
        return dp[u][k] = 1.0;
    }
    if (adj[u].size() == 0)
    {
        return dp[u][k] = 0.0;
    }
    dp[u][k] = 0.0;
    double pt = 1.0 / adj[u].size();
    for (vector <int>::const_iterator it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        for (int i = 1; i <= k - 1; ++i)
        {
            dp[u][k] += dfs(*it, i) * comb[k - 2][i - 1] * pow(pt, i - 1) * pow(1.0 - pt, k - 1 - i) * pt;
        }
    }
    return dp[u][k];
}
double EagleInZoo::calc(vector <int> parent, int K)
{
    int n = parent.size() + 1;
    adj.clear();
    adj.resize(n);
    for (int i = 0; i < n - 1; ++i)
    {
        adj[parent[i]].push_back(i + 1);
    }
    comb.clear();
    comb.resize(K + 1, vector <double>(K + 1, -1.0));
    for (int i = 0; i <= K; ++i)
    {
        comb[i][0] = comb[i][i] = 1.0;
        for (int j = 1; j < i; ++j)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    dp.clear();
    dp.resize(n, vector <double>(K + 1, -1.0));
    return dfs(0, K);
}
// BEGIN CUT HERE
int main()
{
    EagleInZoo __test;
    __test.run_test(-1);
    return 0;
}
// END CUT HERE
