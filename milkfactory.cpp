#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)

void setIO(string name = "")
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("factory");
    int n; cin >> n;
    vector<vector<int>> adjList (n);

    rep(0, n - 1)
    {
        int a, b; cin >> a >> b;
        adjList[a - 1].emplace_back(b - 1);
    }

    int sinks {0};
    vector<int> sink;

    rep(0, n)
    {
        if (adjList[i].size() == 0)
        {
            ++sinks;
            sink.emplace_back(i);
        } 
    }

    if (sinks == 1)
    {
        cout << sink[0] + 1 << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}
