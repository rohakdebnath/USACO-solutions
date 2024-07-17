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

int N, M;
int grid[500][500];
int flag[500][500];
bool vis[500][500];

void dfs(int i, int j, int x){
    if (i < 0 or i >= N or j < 0 or j >= M or vis[i][j]) return;
    vis[i][j] = 1;
    if (abs(grid[i][j + 1] - grid[i][j]) <= x) dfs(i, j + 1, x);
    if (abs(grid[i][j - 1] - grid[i][j]) <= x) dfs(i, j - 1, x);
    if (abs(grid[i + 1][j] - grid[i][j]) <= x) dfs(i + 1, j, x);
    if (abs(grid[i - 1][j] - grid[i][j]) <= x) dfs(i - 1, j, x);
}

bool valid(int x){
    rep(i, 0, N){
        bool flagged = false;
        rep(j, 0, M){
            if (flag[i][j]){
                flagged = true;
                dfs(i, j, x);
                break;
            }
        }
        if (flagged) break;
    }
    rep(i, 0, N){
        rep(j, 0, M){
            if (flag[i][j] == 1 and !vis[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    UNSYNC
    setIO("ccski");
    cin >> N >> M;
    rep(i, 0, N){
        rep(j, 0, M){
            cin >> grid[i][j];
        }
    }
    rep(i, 0, N){
        rep(j, 0, M){
            cin >> flag[i][j];
        }
    }
    int l = -1, r = 1e9 + 1;
    while (r - l > 1){
        int m = l + (r - l)/2;
        if (valid(m)){
            r = m;
        } else {
            l = m;
        }
        memset(vis, 0, sizeof(vis));
    }
    cout << r << '\n';
    return 0;
}
