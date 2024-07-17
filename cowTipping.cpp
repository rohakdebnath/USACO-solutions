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

void update(vector<vector<int>>& cows, int v, int h)
{
    for (int i {0}; i <= v; ++i)
    {
        for (int j {0}; j <= h; ++j)
        {
            cows[i][j] = !cows[i][j];
        }
    }
}

int main()
{
    ifstream read("cowtip.in");
    ofstream written("cowtip.out");

    int n; cin >> n;
    vector<vector<int>> cows (n, vector<int> (n));

    for (int v {0}; v < n; ++v)
    {
        string s; cin >> s;
        for (int h {0}; h < n; ++h)
        {
            cows[v][h] = s[h] - '0';
        }
    }
    int tippinatorUsed {0};

    for (int v {n - 1}; v >= 0; --v)
    {
        for (int h {n - 1}; h >= 0; --h)
        {
            if (cows[v][h] == 1)
            {
                ++tippinatorUsed;
                update(cows, v, h);
            }
        }
    }

    cout << tippinatorUsed << '\n';
    
    return 0;
}
