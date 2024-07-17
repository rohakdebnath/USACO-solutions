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
    setIO("maxcross");
    int N, K, B; cin >> N >> K >> B;
    VI notw (N);
    rep(i, 0, B)
    {
        int n; cin >> n; --n;
        ++notw[n];
    }
    VI prefN (N); prefN[0] = (notw[0] == 0);
    rep(i, 1, N) prefN[i] = prefN[i - 1] + (notw[i] == 0);
    int maxi = prefN[K - 1];
    rep(i, K, N) maxi = max(maxi, prefN[i] - prefN[i - K]);
    cout << K - maxi << '\n';
    return 0;
}
