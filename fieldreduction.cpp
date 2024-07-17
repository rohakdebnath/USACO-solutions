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

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

set<int> extremeIndexes (const vector<int>& X, const vector<int>& Y)
{
    set<int> extremes;
    extremes.insert(distance(X.begin(), max_element(all(X))));
    extremes.insert(distance(X.begin(), min_element(all(X))));
    extremes.insert(distance(Y.begin(), max_element(all(Y))));
    extremes.insert(distance(Y.begin(), min_element(all(Y))));

    return extremes;
}

int main()
{
    setIO("reduce");
    int n; cin >> n;
    vector<int> X (n);
    vector<int> Y (n);
    int minArea = INT32_MAX;

    rep(0, n)
    {
        cin >> X[i];
        cin >> Y[i];
    }
    
    set<int> extremes = extremeIndexes(X, Y);
    for(int i : extremes)
    {
        vector<int> Xa = X;
        vector<int> Ya = Y;
        Xa.erase(Xa.begin() + i);
        Ya.erase(Ya.begin() + i);
        set<int> extremes1 = extremeIndexes(Xa, Ya);

        for (int j : extremes1)
        {
            vector<int> Xb = Xa;
            vector<int> Yb = Ya;
            Xb.erase(Xb.begin() + j);
            Yb.erase(Yb.begin() + j);
            set<int> extremes2 = extremeIndexes(Xb, Yb);

            for (int k : extremes2)
            {
                vector<int> Xc = Xb;
                vector<int> Yc = Yb;
                Xc.erase(Xc.begin() + k);
                Yc.erase(Yc.begin() + k);

                int l = *max_element(all(Xc)) - *min_element(all(Xc));
                int b = *max_element(all(Yc)) - *min_element(all(Yc));

                minArea = min(minArea, l * b);
            }
        }
    }

    cout << minArea << '\n';

    return 0;
}
