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

int countifpresent(VI& v)
{
    int count = 0;
    for (int i : v) if (i != 0) ++count;

    return count;
}
int main()
{
    setIO("lifeguards");
    vector<int> time (1000);
    int n; cin >> n;
    vector<int> start (n);
    vector<int> end (n);

    for (int j = 0; j < n; ++j)
    {
        int s, e; cin >> s >> e;
        start[j] = s;
        end[j] = e;

        for (int i {s}; i < e; ++i) ++time[i];
    }
    int maxTime = 0;
    for (int i = 0; i < n; ++i)
    {
        VI temp = time;
        for (int j = start[i]; j < end[i]; ++j)
        {
            if (temp[j] > 0) --temp[j];
        }
        maxTime = max(maxTime, countifpresent(temp));
    }

    cout << maxTime << '\n';
    return 0;
}
