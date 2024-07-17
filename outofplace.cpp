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
    ifstream read("outofplace.in");
    ofstream written("outofplace.out");

    int n; cin >> n;

    vector<int> cow (n);

    rep(0, n) {cin >> cow[i];}

    vector<int> sortedCow {cow};
    sort(all(sortedCow));

    int outOfPlace {0};

    rep(0, n)
    {
        if (cow[i] != sortedCow[i]) ++outOfPlace;
    }

    cout << max(0, outOfPlace - 1) << '\n';
    
    return 0;
}
