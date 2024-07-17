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
VVI connected;

bitset<1000> vis;
int dfsreach(int s){
    if (vis[s]) return 0;
    vis[s] = 1;
    int reached = 1;
    rep(i, 0, N) if (connected[s][i]) reached += dfsreach(i);
    return reached;
}
int main()
{
    UNSYNC
    setIO("moocast");
    cin >> N;
    connected = VVI (N, VI (N));
    VI x (N), y (N);
    rep(i, 0, N){
        cin >> x[i] >> y[i];
    }
    int l = -1, r = 625000001;
    while (r - l > 1){
        int m = l + (r - l)/2;
        rep(i, 0, N) rep(j, 0, N) connected[i][j] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) <= m;
        int cast = dfsreach(0);
        if (cast == N){
            r = m;
        } else {
            l = m;
        }
        connected = VVI (N, VI (N));
        vis.reset();
    }
    cout << r << '\n';
    return 0;
}
