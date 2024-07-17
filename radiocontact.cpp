#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void setIO(string name = "")
{
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int dist(auto& x, auto& y){
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int main()
{
    UNSYNC
    setIO("radio");
    map<char, int> MP;
    MP['S'] = -1, MP['W'] = -1, MP['E'] = 1, MP['N'] = 1;

    int N, M; cin >> N >> M;
    int fx, fy, bx, by; cin >> fx >> fy >> bx >> by;
    string F, B; cin >> F >> B;
    int x = fx, y = fy;
    vector<pair<int, int>> posF (N + 1);
    posF[0] = {x, y};
    rep(i, 0, N){
        if (F[i] == 'E' or F[i] == 'W') x += MP[F[i]];
        else y += MP[F[i]];
        posF[i + 1] = {x, y};
    }
    x = bx, y = by;
    vector<pair<int, int>> posB (M + 1);
    posB[0] = {x, y};
    rep(i, 0, M){
        if (B[i] == 'E' or B[i] == 'W') x += MP[B[i]];
        else y += MP[B[i]];
        posB[i + 1] = {x, y};
    }
    
    vector<vector<int>> dp (N + 1, vector<int> (M + 1));
    rep(i, 0, N + 1){
        rep(j, 0, M + 1){
            dp[i][j] = INT32_MAX;
        }
    }
    //This is the main part of the dp, notice that at each second, either FJ walks, Bessie walks or both. So to reach a state where FJ walks i steps and Bessie walks j steps, the only way they reach this state is if FJ walked the last step, Bessie walked or Both walked to reach the state. We only have to Pick the best branch out of the previous three possible states. Notice that in a non memoised Recursive program a 3 branched recursive tree would search for the best path making the same choice amongst the three option at each level, we are only avoiding such repititive calculations by working in a specific order (working with prefixes in this example) such that we already store the answers for the best possible branch at each level, this way unneccesary deep searches are avoided.
    dp[0][0] = 0;
    rep(i, 0, N + 1){ //I prefer writing a POG dp in a 0 to N + 1 format, index 0 means no action/step, index N + 1 means the Nth step. 
        rep(j, 0, M + 1){
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist(posF[i], posB[j]));
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + dist(posF[i], posB[j]));
            if (i > 0 and j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + dist(posF[i], posB[j]));
        }
    }
    cout << dp[N][M] << '\n';
    return 0;
}
