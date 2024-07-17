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
    setIO("pails");
    int X, Y, K, M; cin >> X >> Y >> K >> M;
    int depth[101][101];
    memset(depth, -1, sizeof(depth));

    queue<pair<int, int>> bfs; bfs.push({0, 0});
    depth[0][0] = 0;

    while (!bfs.empty()){
        pair<int, int> curs = bfs.front();
        bfs.pop();
        int curl = depth[curs.first][curs.second] + 1;

        int x[] = {X, curs.first, 0, curs.first, max(0, curs.first - (Y - curs.second)), min(curs.first + curs.second, X)};
        int y[] = {curs.second, Y, curs.second, 0, min(curs.first + curs.second, Y), max(0, curs.second - (X - curs.first))};

        rep(i, 0, 6){
            if (curl > K or depth[x[i]][y[i]] != -1) continue;
            depth[x[i]][y[i]] = curl;
            bfs.push({x[i], y[i]});
        }
    }
    int ans = M;
    rep(i, 0, 101){
        rep(j, 0, 101){
            if (depth[i][j] <= K and depth[i][j] != -1) ans = min(ans, abs(i + j - M));
        }
    }
    cout << ans << '\n';
    return 0;
}
