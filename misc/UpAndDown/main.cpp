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
int const N = 1000;
int n;
vector <int> a;
void readin()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
}
bool is_valid(vector <int> const &b)
{
    int max_idx = max_element(b.begin(), b.end()) - b.begin();
    for (int i = 0; i < max_idx; ++i)
    {
        if (b[i] > b[i + 1])
        {
            return false;
        }
    }
    for (int i = n - 1; i > max_idx; --i)
    {
        if (b[i] > b[i - 1])
        {
            return false;
        }
    }
    return true;
}
class Cmp
{
private:
    map <int, int> pos;
public:
    Cmp(vector <int> const &b)
    {
        int n = b.size();
        for (int i = 0; i < n; ++i)
        {
            pos[b[i]] = i;
        }
    }
    bool operator () (int const &x, int const &y)
    {
        return pos[x] < pos[y];
    }
};
int solve()
{
    int ret = INT_MAX;
#ifdef __MY_PC
    vector <int> ans;
#endif
    vector <int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    do
    {
        if (!is_valid(b))
        {
            continue;
        }
        Cmp cmp(b);
        int cur = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (cmp(a[i], a[j]))
                {
                    ++cur;
                }
            }
        }
#ifdef __MY_PC
        if (cur < ret)
        {
            ans = b;
        }
#endif
        ret = min(ret, cur);
    } while (next_permutation(b.begin(), b.end()));
#ifdef __MY_PC
    copy(ans.begin(), ans.end(), ostream_iterator <int>(cerr, " "));
    cerr << endl;
#endif
    return ret;
}
int main()
{
    int tc;
    cin >> tc;
    for (int cc = 1; cc <= tc; ++cc)
    {
        readin();
        printf("Case #%d: %d\n", cc, solve());
    }
    return 0;
}
