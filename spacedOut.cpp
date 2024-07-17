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

int main()
{
    int n; cin >> n;
    vector<vector<int>> canvas (n, vector<int> (n));

    for (int v {0}; v < n; ++v)
    {
        for (int h {0}; h < n; ++h)
        {
            cin >> canvas[v][h];
        }
    }

    int Vmax {0};
    for (int v {0}; v < n; ++v)
    {
        int hLinesum1 {0};
        int hLinesum2 {0};

        for (int h {0}; h < n; h += 2) hLinesum1 += canvas[v][h];
        for (int h {1}; h < n; h += 2) hLinesum2 += canvas[v][h];

        Vmax += max(hLinesum1, hLinesum2);
    }

    int Hmax {0};
    for (int h {0}; h < n; ++h)
    {
        int vLinesum1 {0};
        int vLinesum2 {0};

        for (int v {0}; v < n; v += 2) vLinesum1 += canvas[v][h];
        for (int v {1}; v < n; v += 2) vLinesum2 += canvas[v][h];

        Hmax += max(vLinesum1, vLinesum2);
    }

    cout << max(Hmax, Vmax) << '\n';
    return 0;
}
