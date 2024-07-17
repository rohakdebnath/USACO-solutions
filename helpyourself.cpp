#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const i64 MOD = 1e9 + 7;
i64 exp(i64 base, i64 pow){
    i64 res = 1;
    while (pow){
        if (pow & 1) res = res * base % MOD;
        base = base * base % MOD;
        pow /= 2;
    }
    return res;
}

int main()
{
    UNSYNC
    setIO("help");
    int N; cin >> N;
    vector<int> terminals (2*N + 1);
    rep(i, 0, N){
        int l, r; cin >> l >> r;
        ++terminals[l];
        --terminals[r];
    }

    int opens = 0;
    int ans = 0;
    rep(i, 1, 2*N + 1){
        opens += terminals[i];
        if (terminals[i] == 1){
            ans = (ans + exp(2, N - opens)) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}
