#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>
template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

int N, M;
char grid[50][50];
int vis[50][50];

void dfs (int i, int j){
    if (i < 0 or j < 0 or i > N - 1 or j > M - 1 or vis[i][j] or grid[i][j] == '#'){
        return;
    }
    vis[i][j] = 1;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
    return;
}

void solve()
{
    cin >> N >> M;
    memset(grid, '.', sizeof(grid));
	memset(vis, 0, sizeof(vis));
    rep(i, 0, N){
        rep(j, 0, M){
            cin >> grid[i][j];
        }
    }

    bool srv = true;
    rep(i, 0, N){
        rep(j, 0, M){
            if (grid[i][j] == 'B'){
                if (i > 0){
                    if (grid[i - 1][j] == 'G'){
                        srv = false;
                        break;
                    }
                    if (grid[i - 1][j] == '.'){
                        grid[i - 1][j] = '#';
                    }
                }
                if (i < N - 1){
                    if (grid[i + 1][j] == 'G'){
                        srv = false;
                        break;
                    }
                    if (grid[i + 1][j] == '.'){
                        grid[i + 1][j] = '#';
                    }
                }
                if (j > 0){
                    if (grid[i][j - 1] == 'G'){
                        srv = false;
                        break;
                    }
                    if (grid[i][j - 1] == '.'){
                        grid[i][j - 1] = '#';
                    }
                }
                if (j < M - 1){
                    if (grid[i][j + 1] == 'G'){
                        srv = false;
                        break;
                    }
                    if (grid[i][j + 1] == '.'){
                        grid[i][j + 1] = '#';
                    }
                }
            }
        }
    }
    if (!srv){
        cout << "NO\n";
        return;
    }
    if (grid[N - 1][M - 1] == '.') dfs (N - 1, M - 1);
    rep(i, 0, N){
        rep(j, 0, M){
            if (grid[i][j] == 'G' and !vis[i][j]){
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
