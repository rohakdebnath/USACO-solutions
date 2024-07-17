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

int N, dx[] = {1, 0, 0, -1}, dy[] = {0, 1, -1, 0};
char grid[202][202];
bool vis[202][202];

int cows = 0;
void dfs(int i, int j){
    if (vis[i][j] or grid[i][j] == '#') return;
    vis[i][j] = 1;
    cows += grid[i][j] == 'c';
    rep(t, 0, 4){
        int ni = i + dx[t], nj = j + dy[t];
        dfs(ni, nj);
    }
    return;
}

int main()
{
    UNSYNC
    setIO("countcross");
    memset(grid, '#', sizeof(grid));
    int K, R; cin >> N >> K >> R;
    rep(i, 1, 2*N){
        rep(j, 1, 2*N){
            grid[i][j] = '.';
        }
    }
    rep(i, 0, R){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int l = a + c - 1, m = b + d - 1;
        if (l & 1){
            for (int x = l - 1; x <= l + 1; ++x){
                grid[x][m] = '#';
            }
        } else {
            for (int x = m - 1; x <= m + 1; ++x){
                grid[l][x] = '#';
            }
        }
    }
    rep(i, 0, K){
        int x, y; cin >> x >> y;
        grid[2*x - 1][2*y - 1] = 'c';
    }

    VI ccows;
    rep(i, 1, 2*N){
        rep(j, 1, 2*N){
            if (!vis[i][j]){
                dfs(i, j);
                if (cows) ccows.push_back(cows);
                cows = 0;
            }
        }
    }

    VI pfccows (ccows.size()); partial_sum(ccows.rbegin(), ccows.rend(), pfccows.rbegin());
    int ans = 0;
    rep(i, 0, ccows.size() - 1){
        ans += ccows[i]*pfccows[i + 1];
    }
    cout << ans << '\n';
    return 0;
}
