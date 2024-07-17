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
    int odds {0};
    int evens {0};

    rep(0, n)
    {
        int k; cin >> k;
        if (k % 2) ++odds;
        else ++evens;
    }

    if (evens == odds)
    {
        cout << evens + odds << '\n';
        return 0;
    }

    else if (evens > odds)
    {
        cout << 2*odds + 1 << '\n';
        return 0;
    }
    else
    {
        while (true)
        {
            if (odds == evens + 1)
            {
                cout << odds + evens - 2 << '\n';
                return 0;
            }
            if (odds == evens or odds + 1 == evens)
            {
                cout << odds + evens << '\n';
                return 0;
            }
            odds -= 2;
            ++evens;
        }
    }
    return 0;
}
