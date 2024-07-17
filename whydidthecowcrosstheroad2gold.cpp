#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC cin.tie(0)->sync_with_stdio(0);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

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
    setIO("nocross");
    int N; cin >> N;
    vector<int> A (N); rep(i, 0, N) cin >> A[i];
    vector<int> B (N); rep(i, 0, N) cin >> B[i];

    vector<vector<int>> dp (N + 1, vector<int> (N + 1));

    rep(i, 1, N + 1){
        rep(j, 1, N + 1){
            if (abs(A[i - 1] - B[j - 1]) <= 4){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }   
    cout << dp[N][N] << '\n';
    return 0;
}
