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

VI tree[2500];
VI blue;
VI red;

void dfs (i64 s, i64 p, i64 col){
    col ? blue.push_back(s) : red.push_back(s);
    for (i64 u: tree[s]){
        if (u == p) continue;
        dfs(u, s, !col);
    }
    return;
}

int main()
{
    UNSYNC
    setIO("clocktree");
    i64 N; cin >> N;
    VI A (N); rep(i, 0, N) cin >> A[i];

    rep(i, 0, N - 1){
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(0, -1, 0);

    i64 redsum = accumulate(all(red), 0LL, [&] (i64 s, i64 i) {
        return s + A[i];
    }) % 12;
    i64 bluesum = accumulate(all(blue), 0LL, [&] (i64 s, i64 i) {
        return s + A[i];
    }) % 12;

    if (redsum % 12 == bluesum % 12){
        cout << N << '\n';
    } else if (redsum % 12 == (bluesum + 1) % 12){
        cout << red.size() << '\n';
    } else if ((redsum + 1) % 12 == bluesum % 12){
        cout << blue.size() << '\n';
    } else {
        cout << "0\n";
    }
    return 0;
}
