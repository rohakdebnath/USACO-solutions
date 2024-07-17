#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void setIO(string name = "")
{
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int shift = 1e6;
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // setIO("threesum");

    int n, q; cin >> n >> q;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<i64>> dp (n, vector<i64> (n, 0)); //dp[i][j] = number of 3sum = 0 in subarray i..j
    vector<int> f (2 * shift);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            int c = shift - a[i] - a[j];
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + (c >= 0 and c < 2 * shift ? f[c] : 0) ;
            ++f[a[j] + shift];
        }
        for (int j = i + 1; j < n; j++) f[a[j] + shift]--;
    }
    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        cout << dp[l][r] << '\n';
    }
    return 0;
}
