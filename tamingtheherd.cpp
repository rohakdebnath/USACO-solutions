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
#define cin read
#define cout written

int main()
{
    ifstream read("taming.in");
    ofstream written("taming.out");

    int n; cin >> n;
    vector<int> log (n);

    rep(0, n) {cin >> log[i];}

    log[0] = 0;

    int breakOutDays {0};
    for (int i {n - 1}; i > 0; --i)
    {
        if (log[i] >= 1)
        {
            if (log[i - 1] == -1) log[i - 1] = log[i] - 1;
            else if (log[i - 1] != log[i] - 1)
            {
                cout << - 1 << '\n';
                return 0;
            }
        }
        else if (log[i] == 0) ++breakOutDays;
    }

    ++breakOutDays;

    int mightBe = count(all(log), -1);

    cout << breakOutDays << ' ' << breakOutDays + mightBe << '\n';
    return 0;
}
