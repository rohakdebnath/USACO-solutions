#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
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
    setIO("reststops");
    int L, N, rf, rb; cin >> L >> N >> rf >> rb;
    VI dist (N), taste (N);
    rep(i, 0, N) cin >> dist[i] >> taste[i];
    
    VI pidx (N); iota(all(pidx), 0);
    sort(all(pidx), [&] (int i, int j) {
        return dist[i] < dist[j];
    });
    sort(all(dist));

    int currcov = 0;
    i64 maxt = 0;
    i64 ans = 0;
    per(i, N - 1, 0){
        if (taste[pidx[i]] > maxt){
            maxt = taste[pidx[i]];
            ans += dist[i]*(maxt - currcov)*(rf - rb);
            currcov = maxt;
        }
        else continue;
    }
    cout << ans << '\n';
    return 0;
}
