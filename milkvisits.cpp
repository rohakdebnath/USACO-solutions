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
    setIO("milkvisits");
    int N, M; cin >> N >> M;
    string S; cin >> S;
    VI adj[100000];
    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int color = 0;
    VI ccc (N, -1);
    rep(i, 0, N){
        if (ccc[i] != -1) continue;
        char cow = S[i];
        queue<int> bfs; 
        bfs.push(i);
        ccc[i] = color;
        while (!bfs.empty()){
            int top = bfs.front();
            bfs.pop();
            for (int u: adj[top]){
                if (ccc[u] == -1 and S[u] == cow){
                    bfs.push(u);
                    ccc[u] = color;
                }
            }
        }
        ++color;
    }
    rep(i, 0, M){
        int a, b; cin >> a >> b; --a, --b;
        char c; cin >> c;
        if (ccc[a] == ccc[b]){
            if (S[a] == c) cout << 1;
            else cout << 0;
        } else {
            cout << 1;
        }
    }
    cout << '\n';
    return 0;
}
