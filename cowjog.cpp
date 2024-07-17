#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const i64 MOD = INT64_MAX;
int main()
{
    UNSYNC
    setIO("cowjog");
    i64 N, T; cin >> N >> T;
    vector<i64> fin (N);
    rep(i, 0, N){
        i64 x, t; cin >> x >> t;
        fin[i] = x + t * T;
    }
    reverse(all(fin));
    vector<i64> dp (N + 1, MOD); dp[0] = -MOD;
        
    rep(i, 0, N){
        i64 l = upper_bound(all(dp), fin[i]) - dp.begin();
        dp[l] = fin[i];
    }
    i64 ans = 0;
    rep(i, 0, N){
        if (dp[i] < MOD) ans = i;
    }
    cout << ans << '\n';
    return 0;
}
