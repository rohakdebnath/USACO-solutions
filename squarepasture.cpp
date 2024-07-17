#include <bits/stdc++.h>

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
    UNSYNC
    setIO("square");
    vector<int> x (4);
    vector<int> y (4);
    cin >> x[0] >> y[0] >> x [1] >> y[1] >> x[2] >> y[2] >> x [3] >> y[3];
    
    int X = *max_element(all(x)) - *min_element(all(x));
    int Y = *max_element(all(y)) - *min_element(all(y));
    cout << max(X, Y)*max(X, Y) << '\n';
    return 0;
}
