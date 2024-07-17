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
    string s; cin >> s;
    string p {""};

    for (int i {1}; i < n; i += 2)
    {
        if (s.substr(i - 1, 2) == "HG") p += "T";
        else if (s.substr(i - 1, 2) == "GH") p += "F";
    }

    string r {""};
    for (int i {0}; i < p.size() - 1; ++i)
    {
        if (p[i] != p[i + 1]) r +=p[i];
    }

    if (*(p.end() - 1) == 'F') r += 'F';

    cout << r.size() << '\n';
    
    return 0;
}
