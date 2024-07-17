#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

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
    setIO("socdist");
    i64 N, M; cin >> N >> M;
    vector<pair<i64, i64>> patch (M);
    rep(i, 0, M) cin >> patch[i].first >> patch[i].second;
    sort(all(patch));

    i64 l = 0, r = 1e18 + 1;
    while(r - l > 1){ //LTBS ftw
        i64 m = l + (r - l)/2;
        i64 last = 0, placed = 0, i = 0;
        while(i < M and last < patch[M - 1].second){
            last = max(last, patch[i].first) + m;
            ++placed;
            while (last > patch[i].second and i < M) ++i;
        }
        if (placed >= N){
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
    return 0;
}
