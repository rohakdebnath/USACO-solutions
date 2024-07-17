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

i64 dist(const pair<i64, i64>& A, const pair<i64, i64>& B){
    return (A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second);
}

int main()
{
    UNSYNC
    setIO("checklist");
    i64 N, M; cin >> N >> M;
    vector<pair<i64, i64>> Hpos (N + 1);
    vector<pair<i64, i64>> Gpos (M + 1);

    rep(i, 0, N){
        cin >> Hpos[i + 1].first >> Hpos[i + 1].second;
    }
    rep(i, 0, M){
        cin >> Gpos[i + 1].first >> Gpos[i + 1].second;
    }
    
    vector<vector<vector<i64>>> dp (N + 1, vector<vector<i64>> (M + 1, vector<i64> (2)));
    rep(i, 0, N + 1){
        rep(j, 0, M + 1){
            rep(k, 0, 2){
                dp[i][j][k] = INT32_MAX;
            }
        }
    }
    dp[1][0][0] = 0;
    rep(i, 0, N + 1){
        rep(j, 0, M + 1){
            if (i > 0) dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][0] + dist(Hpos[i], Hpos[i - 1]), dp[i - 1][j][1] + dist(Hpos[i], Gpos[j])});
            if (j > 0) dp[i][j][1] = min({dp[i][j][1], dp[i][j - 1][1] + dist(Gpos[j], Gpos[j - 1]), dp[i][j - 1][0] + dist(Hpos[i], Gpos[j])});
        }
    }
    cout << dp[N][M][0] << '\n';
    return 0;
}
