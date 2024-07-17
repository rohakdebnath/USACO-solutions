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

struct Wormhole{
    int a = 0;
    int b = 0;
    int weight = 0;

    friend bool operator<(const Wormhole& i, const Wormhole& j){
        return i.weight > j.weight;
    }
};

VVI adj;
bitset<100000> vis;
VI components;
void dfs (int n){
    if (vis[n]) return;
    vis[n] = 1;
    components.push_back(n);
    for (int u : adj[n]) dfs(u);
    return;
}

int main()
{
    UNSYNC
    // setIO("wormsort");
    int N, M; cin >> N >> M;
    adj.resize(N);
    VI p (N); rep(i, 0, N) cin >> p[i], --p[i];
    vector<vector<int>> needed;
    rep(i, 0, N){
        if (p[i] != i) needed.push_back({i, p[i]});
    }

    vector<Wormhole> wormholes (M);
    rep(i, 0, M){
        cin >> wormholes[i].a >> wormholes[i].b >> wormholes[i].weight;
        --wormholes[i].a, --wormholes[i].b;
    }
    sort(all(wormholes));

    if (needed.size() == 0){
        cout << "-1\n";
        return 0;
    }

    int l = -1, r = M;
    while (r - l > 1){
        int m = l + (r - l)/2;
        VI cccoloring (N);
        VVI ccomponents;
        rep(i, 0, m + 1){
            adj[wormholes[i].a].push_back(wormholes[i].b);
            adj[wormholes[i].b].push_back(wormholes[i].a);
        }
        rep(i, 0, N){
            dfs(i);
            ccomponents.push_back(components);
            components.clear();
            components.resize(0);
        }
        vis.reset(); //reset vis
        int color = 1;
        for (auto v: ccomponents){
            for(int i: v) cccoloring[i] = color;
            ++color; 
        }
        bool survive = true;
        rep(i, 0, needed.size()){
            if (cccoloring[needed[i][0]] != cccoloring[needed[i][1]]){
                survive = false;
                break;
            }
        }
        adj.clear();
        adj.resize(N); //and reset the adjacency list
        if (!survive){
            l = m;
        } else {
            r = m;
        }

        vector<int> id (N); iota(all(id), 0);
        sort(all(id), [&] (int i, int j) {return A[i] < A[j];});
        vector<int> pid (N);
        rep(i, 0, N) pid[id[i]] = i;
    }  
    cout << wormholes[r].weight << '\n';
    return 0;
}
