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

const int inf = 1e9;
signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // setIO("cowrun");
    int n; cin >> n;
    vector<int> a (n); for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (n + 1, vector<int> (2, inf)));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            int l = n - (j - i);
            if (i == j) {
                dp[i][j][1] = l * abs(a[i]);
                dp[i][j][0] = l * abs(a[i]);
            } else {
                if (j - 1 >= 0) dp[i][j][1] = min(dp[i][j - 1][1] + (a[j] - a[j - 1]) * l, dp[i][j - 1][0] + (a[j] - a[i]) * l);
                if (i + 1 <= n) dp[i][j][0] = min(dp[i + 1][j][0] + (a[i + 1] - a[i]) * l, dp[i + 1][j][1] + (a[j] - a[i]) * l);
            }
        }
    }
    cout << min(dp[0][n - 1][1], dp[0][n - 1][0]) << '\n';
    return 0;
}
