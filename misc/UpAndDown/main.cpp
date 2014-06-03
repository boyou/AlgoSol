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
int solve()
{
    int ret = 0;
    while (!a.empty())
    {
        vector <int>::iterator it = min_element(a.begin(), a.end());
        ret += min(it - a.begin(), a.end() - it - 1);
        a.erase(it);
    }
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
