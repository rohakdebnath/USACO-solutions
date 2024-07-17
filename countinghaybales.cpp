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
    setIO("haybales");
    int N, Q; cin >> N >> Q;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));
    rep(i, 0, Q){
        int l, r; cin >> l >> r;
        cout << upper_bound(all(A), r) - lower_bound(all(A), l) << '\n';
    }
    
    return 0;
}
