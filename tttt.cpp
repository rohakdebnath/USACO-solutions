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

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("tttt");
    vector<string> tttt (3);
    for (string& s: tttt) {cin >> s;}

    set<set<char>> unique;

    for (int v {0}; v < 3; ++v)
    {
        set<char> Hline;
        for (int h {0}; h < 3; ++h)
        {
            Hline.insert(tttt[v][h]);
        }
        unique.insert(Hline);
    }

    set<char> diag1;
    for (int v {0}; v < 3; ++v)
    {
        for (int h {0}; h < 3; ++h)
        {
            if (h == v)
            {
                diag1.insert(tttt[v][h]);
                break;
            }
        }
    }
    unique.insert(diag1);
    diag1.clear();

    for (int v {0}; v < 3; ++v)
    {
        for (int h {0}; h < 3; ++h)
        {
            if (h + v == 2)
            {
                diag1.insert(tttt[v][h]);
                break;
            }
        }
    }
    unique.insert(diag1);
    diag1.clear();

    for (int h {0}; h < 3; ++h)
    {
        set<char> Vline;
        for (int v {0}; v < 3; ++v)
        {
            Vline.insert(tttt[v][h]);
        }
        unique.insert(Vline);
    }
    int doubles = 0;
    int singles = 0;

    for (auto& i : unique)
    {
        if (i.size() == 1) ++singles;
        else if (i.size() == 2) ++doubles;
    }
    cout << singles << '\n' << doubles << '\n';
    return 0;
}
