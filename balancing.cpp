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
    setIO("balancing");
    int n; cin >> n;
    vector<pair<int, int>> points (n);
    rep(0, n) cin >> points[i].first >> points[i].second;
    sort(all(points));
    
    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i)
    {
        int y = points[i].second;
        int tl = 0, br = 0, tr = 0, bl = 0;
        for (int j = 0; j < n; ++j)
        {
            if (points[j].second > y) ++tr;
            else ++br;
        }
        for (int j = 0; j < n; ++j)
        {
            if (points[j].second > y)
            {
                ++tl;
                --tr;
            }
            else
            {
                ++bl;
                --br;
            }
            ans = min(ans, max({tr, tl, bl, br}));
        }
    }
    cout << ans << '\n';
    return 0;
}
