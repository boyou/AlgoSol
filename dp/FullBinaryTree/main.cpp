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
vector <vector <int> > adj;
vector <bool> visited;
void readin()
{
    scanf("%d", &n);
    adj.clear();
    adj.resize(n + 1);
    visited.clear();
    visited.resize(n + 1);
    for (int i = 0, j, k; i < n - 1; ++i)
    {
        scanf("%d%d", &j, &k);
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
}
pair <int, int> dfs(int u)
{
    visited[u] = true;
    int ch[2] = {INT_MAX >> 2, INT_MAX >> 2};
    int num_children = 0;
    for (vector <int>::const_iterator it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        int v = *it;
        if (visited[v])
        {
            continue;
        }
        pair <int, int> p = dfs(v);
        num_children += 1 + p.second;
        if (p.first - (p.second + 1) < ch[0])
        {
            ch[1] = ch[0];
            ch[0] = p.first - (p.second + 1);
        }
        else if (p.first - (p.second + 1) < ch[1])
        {
            ch[1] = p.first - (p.second + 1);
        }
    }
    int ret = min(num_children, num_children + ch[0] + ch[1]);
    return make_pair(ret, num_children);
}
int solve()
{
    int ret = INT_MAX;
    for (int i = 1; i <= n; ++i)
    {
        fill(visited.begin(), visited.end(), false);
        pair <int, int> p = dfs(i);
        ret = min(ret, p.first);
    }
    return ret;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    for (int cc = 1; cc <= tc; ++cc)
    {
        readin();
        printf("Case #%d: %d\n", cc, solve());
        fprintf(stderr, "%d...\n", cc);
    }
    return 0;
}
