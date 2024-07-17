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

vector<pair<int, int>> adj[5000];
bitset<5000> vis;
int K, ans;
void dfs(int s){
    vis[s] = 1;
    for (auto p: adj[s]){
        if (!vis[p.first] and p.second >= K){ //this operation would not work if the relevance between nodes were defined as the "maximum" of the path component' relevance.
            ++ans;
            dfs(p.first);
        }
    }
}

int main()
{
    UNSYNC
    setIO("mootube");
    int N, Q; cin >> N >> Q;
    rep(i, 0, N - 1){
        int p, q, r; cin >> p >> q >> r; --p, --q;
        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    rep(i, 0, Q){
        int V; cin >> K >> V; 
        vis.reset(), ans = 0;
        dfs(V - 1);
        cout << ans << '\n';
    }
    
    return 0;
}
