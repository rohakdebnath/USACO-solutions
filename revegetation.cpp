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
    setIO("revegetate");
    int n, m; cin >> n >> m;
    vector<vector<int>> adjList (n);

    rep(0, m)
    {
        int a, b; cin >> a >> b;
        adjList[a - 1].emplace_back(b - 1);
        adjList[b - 1].emplace_back(a - 1);
    }

    vector<int> seedTypeat (n);
    seedTypeat[0] = 1;

    rep(1, n)
    {
        for (int j {1}; j <= 4; ++j)
        {
            bool survive {true};
            for (int k : adjList[i]) if (seedTypeat[k] == j) survive = false;
            if (survive)
            {
                seedTypeat[i] = j;
                break;
            }
        }
    }

    rep(0, n) cout << seedTypeat[i];
    cout << '\n';    
    return 0;
}
