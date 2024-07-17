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

map<pair<int, int>, vector<pair<int, int>>> lightmap;
int N;
int lit[100][100];
bool vis[100][100];

void dfs (int i, int j){
    if (i < 0 or j < 0 or i > N - 1 or j > N - 1 or vis[i][j] or !lit[i][j]) return;
    vis[i][j] = 1;
    for (auto p: lightmap[{i, j}]){
        lit[p.first][p.second] = 1;
        if ((p.first > 0 and vis[p.first - 1][p.second]) or (p.second > 0 and vis[p.first][p.second - 1]) or (p.first < N - 1 and vis[p.first + 1][p.second]) or (p.second < N - 1 and vis[p.first][p.second + 1])){
            dfs(p.first, p.second);
        }
    }
    dfs(i - 1, j);
    dfs(i, j - 1);
    dfs(i + 1, j);
    dfs(i, j + 1);
}

int main()
{
    UNSYNC
    setIO("lightson"); 
    cin >> N;
    int M; cin >> M;
    rep(i, 0, M){
        int a, b, x, y; cin >> a >> b >> x >> y; 
        lightmap[{--a, --b}].push_back({--x, --y});
    }
    lit[0][0] = 1;
    dfs(0, 0);
    int count = 0;
    rep(i, 0, N){
        rep(j, 0, N){
            count += lit[i][j];
        }
    }
    cout << count << '\n';
    return 0;
}
