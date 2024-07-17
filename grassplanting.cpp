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
    ifstream cin("planting.in");
    ofstream cout("planting.out");

    int n; cin >> n;
    vector<int> adjList (n);

    int maxBranch {0};
    rep(0, n - 1)
    {
        int a, b; cin >> a >> b;

        ++adjList[a - 1];
        ++adjList[b - 1];

        maxBranch = max({maxBranch, adjList[a - 1], adjList[b - 1]});
    }

    cout << maxBranch + 1 << '\n';
    
    return 0;
}
