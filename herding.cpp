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
    ifstream read("herding.in");
    ofstream written("herding.out");
    vector<int> pos (3);
    cin >> pos[0] >> pos[1] >> pos[2];
    sort(all(pos));
    int mini = min(pos[2] - pos[1] - 1, pos[1] - pos[0] - 1);
    int maxi = max(pos[2] - pos[1] - 1, pos[1] - pos[0] - 1);

    if (mini == 0 and maxi == 0)
    {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }
    else if (mini == 0 and maxi == 1)
    {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }
    else if (mini == 0 and maxi >= 2)
    {
        cout << 2 << '\n';
        cout << maxi << '\n';
        return 0;
    }
    else
    {
        cout << min(mini,2) << '\n';
        cout << maxi << '\n';
        return 0;
    }
    return 0;
}
