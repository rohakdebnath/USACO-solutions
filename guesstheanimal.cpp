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
#define VI vector<int>
#define VVI vector<vector<int>>

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int intersec(const vector<string>& a1, const vector<string>& a2)
{
    int rep = 0;
    for (auto s : a1)
    {
        if (count(all(a2), s) != 0) ++rep;
    }
    return rep;
}

int main()
{
    setIO("guess");
    int n; cin >> n;
    vector<vector<string>> v (n);
    rep(0, n)
    {
        string s; cin >> s;
        int k; cin >> k;
        for (int j = 0; j < k; ++j)
        {
            string ch; cin >> ch;
            v[i].emplace_back(ch);
        }
    }

    int maxc = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            maxc = max(maxc, intersec(v[i], v[j]));
        }
    }
    
    cout << maxc + 1 << '\n';
    return 0;
}
