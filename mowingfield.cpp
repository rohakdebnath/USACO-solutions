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
    setIO("mowing");
    int N; cin >> N;
    int x = 0, y = 0, t = 0;
    map<pair<int, int>, int> status;
    status[{0, 0}] = 0;

    int ans = INT32_MAX;

    rep(0, N)
    {
        char c; cin >> c;
        int n; cin >> n;
        while (n--)
        {
            ++t;
            if (c == 'N') ++y;
            else if (c == 'S') --y;
            else if (c == 'E') ++x;
            else if (c == 'W') --x;
            if (status.count({x, y})) ans = min(ans, t - status[{x, y}]);
            status[{x, y}] = t;
        }
    }

    cout << ((ans == INT32_MAX) ? -1 : ans) << '\n';
    return 0;
}
