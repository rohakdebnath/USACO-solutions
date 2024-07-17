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

int n; 
VVI connected;
bitset<200> visited;

int reachable(int s) //dfs and the connected nodes are decided by connected[s][i] being true;
{
    if (visited[s]) return 0;
    visited[s] = 1;
    int reached = 1;
    rep(i, 0, n) if (connected[s][i]) reached += reachable(i);
    return reached;
}

int main()
{
    UNSYNC
    setIO("moocast");
    cin >> n;
    connected = VVI (n, VI (n));
    VI x (n), y (n), power (n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> power[i];

    rep(i, 0, n) rep(j, 0, n) connected[i][j] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) <= power[i]*power[i];

    int maxcast = 0;
    rep(i, 0, n)
    {
        visited.reset();
        maxcast = max(maxcast, reachable(i));
    }

    cout << maxcast << '\n';
    return 0;
}
