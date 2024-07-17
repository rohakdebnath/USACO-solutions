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

struct Cow
{
    int x;
    int y;
    vector<int> adj;
    bool visited;
};

vector<Cow> cows;
vector<int> network;
void dfs(int i)
{
    if (cows[i].visited) return;
    cows[i].visited = true;
    network.push_back(i);
    for(int j: cows[i].adj) dfs(j); 
}

int main()
{
    UNSYNC
    setIO("fenceplan");
    int N, M; cin >> N >> M;
    cows.resize(N);

    rep(i, 0, N)
    {
        cin >> cows[i].x >> cows[i].y;
        cows[i].visited = false;
    }

    rep(i, 0, M)
    {
        int a, b; cin >> a >> b;
        cows[a - 1].adj.push_back(b - 1);
        cows[b - 1].adj.push_back(a - 1);
    }

    vector<vector<int>> components;
    rep(i, 0, N)
    {
        network.clear();
        if (cows[i].visited) continue;
        dfs(i);
        components.push_back(network);
    }


    int minper = INT32_MAX;
    for(vector<int> currnetwork: components)
    {
        int xmax = 0;
        int xmin = INT32_MAX;
        int ymax = 0;
        int ymin = INT32_MAX;
        for (int i : currnetwork)
        {
            xmax = max(xmax, cows[i].x);
            xmin = min(xmin, cows[i].x);
            ymax = max(ymax, cows[i].y);
            ymin = min(ymin, cows[i].y);
        }
        minper = min(minper, 2*(xmax - xmin + ymax - ymin));
    }

    cout << minper << '\n';
    return 0;
}
