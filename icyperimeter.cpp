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

int N; 
char grid[1000][1000];
bool vis[1000][1000];
int maxrea = 0;
int curea = 0;
int curperi = 0;

void dfs(int i, int j){
    if (i < 0 or i >= N or j < 0 or j >= N){
        ++curperi;
        return;
    }
    if (vis[i][j]) return;
    if (grid[i][j] == '.'){
        ++curperi;
        return;
    }
    if (grid[i][j] == '#') ++curea;
    vis[i][j] = 1;
    dfs(i, j - 1);
    dfs(i, j + 1);
    dfs(i + 1, j);
    dfs(i - 1, j);
    return;
}

int main()
{
    UNSYNC
    setIO("perimeter");
    cin >> N;
    int maxperi = 0;
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> grid[i][j];
        }
    }
    rep(i, 0, N){
        rep(j, 0, N){
            if (!vis[i][j] and grid[i][j] == '#'){
                dfs(i, j);
            }
            if (curea == maxrea){
                maxperi = min(maxperi, curperi);
            } else if (curea > maxrea){
                maxrea = curea;
                maxperi = max(maxperi, curperi);
            }
            curperi = curea = 0;
        }
    }
    cout << maxrea << ' ' << maxperi << '\n';
    return 0;
}
