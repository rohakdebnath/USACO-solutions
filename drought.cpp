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

void solve()
{
    i64 n; cin >> n;
    vector<i64> h (n);
    rep(0, n) {cin >> h[i];}
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    vector<i64> mh = h;

    for (i64 i {n - 2}; i > 0; --i)
    {
        if (mh[i] > mh[i + 1])
        {
            mh[i - 1] -= (mh[i] - mh[i + 1]);
            mh[i] = mh[i + 1];
        }
        if (mh[i - 1] < 0)
        {
            cout << -1 << '\n';
            return;
        }
    }
    if (mh[0] > mh[1] or mh[n - 1] > mh[n - 2])
    {
        cout << - 1 << '\n';
        return;
    }

    i64 diffs {0};
    for (i64 i : h)
    {
        diffs += i - mh[0];
    }
    cout << diffs << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
