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

int main()
{
    int n; cin >> n;
    vector<pair<int, char>> dir (n); 

    rep(0, n)
    {
        cin >> dir[i].second >> dir[i].first;
    } 

    sort(all(dir));

    vector<int> left (n);

    for(int i = 1; i < n; ++i)
    {
        left[i] += left[i - 1];
        if (dir[i - 1].second == 'L' and dir[i].first > dir[i - 1].first)
        {
            ++left[i];
        }
    }

    vector<int> right (n);
    for(int i = n - 2; i >= 0; --i)
    {
        right[i] += right[i + 1];
        if (dir[i + 1].second == 'G' and dir[i].first < dir[i + 1].first)
        {
            ++right[i];
        }
    }

    int minR = n;
    rep(0, n)
    {
        minR = min(minR, right[i] + left[i]);
    }

    cout << minR << '\n';
    return 0;
}
