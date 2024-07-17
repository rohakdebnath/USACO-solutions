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

void solve()
{
    int N, C; cin >> N >> C;
    VI stall (N); rep(i, 0, N) cin >> stall[i];
    sort(all(stall));

    int ans = *ranges::partition_point(ranges::iota_view(1, stall[N - 1] - stall[0] + 1), [&] (int i) {
        int cownt = 1; int last = stall[0];
        rep(t, 1, N){
            if (stall[t] - last >= i){
                ++cownt;
                last = stall[t];
                if (cownt == C) return true;
            }
        }
        return false;
    }) - 1;
    cout << ans << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
