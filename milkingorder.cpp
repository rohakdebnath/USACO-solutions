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
    ifstream read("milkorder.in");
    ofstream written("milkorder.out");

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cowatpos (n + 1);
    vector<int> posofcow (n + 1);
    vector<int> hierarchy(m);

    rep(0, m) {cin >> hierarchy[i];}

    rep(0,k)
    {
        int c, p;
        cin >> c >> p;

        if (c == 1)
        {
            cout << p << '\n';
            return 0;
        }

        cowatpos[p] = c;
        posofcow[c] = p;
    }

    int pointat {n};
    for(int i {m - 1}; i >= 0; --i)
    {
        int curr {hierarchy[i]};
        if (curr == 1)
        {
            pointat = 1;
            for (int j {0}; j <= i; ++j)
            {
                curr = hierarchy[j];
                if (posofcow[curr])
                {
                    pointat = posofcow[curr] + 1;
                    continue;
                }
                while (cowatpos[pointat]) ++pointat;
                cowatpos[pointat] = curr;
                ++pointat;
            }
            cout << pointat - 1 << '\n';
            return 0;
        }
        if (posofcow[curr])
        {
            pointat = posofcow[curr] - 1;
            continue;
        }
        while (cowatpos[pointat]) --pointat;
        cowatpos[pointat] = curr;
        --pointat;
    }

    for (int i {1}; i <= n; ++i)
    {
        if (cowatpos[i] == 0)
        {
            cout << i << '\n';
            return 0;
        }
    }
    
    return 0;
}
