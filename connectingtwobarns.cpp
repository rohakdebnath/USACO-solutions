#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

const i64 MAX = 1e5;

VI adj[MAX];
VI comps[MAX]; //this is an index wise connected component matrix
i64 comp[MAX];

i64 cost(i64 a, i64 b) {
	i64 dist = MAX;
	for (i64 u : comps[a]) {
		i64 i = lower_bound(comps[b].begin(), comps[b].end(), u) - comps[b].begin();
		if (i > 0) dist = min(dist, abs(comps[b][i - 1] - u));
		if (i < comps[b].size()) dist = min(dist, abs(comps[b][i] - u));
	}
	return dist * dist;
}

void dfs(i64 s, i64 in){
    comp[s] = in;
    for(i64 u: adj[s]) if (comp[u] == -1) dfs(u, in);
}

void solve()
{
    i64 N, M; cin >> N >> M;
    for (i64 i = 0; i < N; i++) {
		comp[i] = -1;
		adj[i].clear();
		comps[i].clear();
	}

    rep(i, 0, M){
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    i64 curind = -1;
    rep(i, 0, N){
        if (comp[i] == -1){
            dfs(i, ++curind);
        }
    }
    rep(i, 0, N) comps[comp[i]].push_back(i);

    i64 mincost = cost(comp[0], comp[N - 1]);
    rep(i, 1, curind){
        mincost = min(mincost, cost(i, comp[0]) + cost(i, comp[N - 1]));
    }

    cout << mincost << '\n';
}

int main()
{
    UNSYNC
    i64 T;
    cin >> T;
    while(T--) solve();
    return 0;
}
