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
    setIO("diamond");
    int N, K; cin >> N >> K;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));
    VI ifleftatl (N);
    int l = 0, r = 0;
    for(; l < N; ++l){
        while(r < N and A[r] - A[l] <= K) ++r;
        ifleftatl[l] = r - l;
    }

    VI froml (N + 1); froml[N] = 0;
    for(int i = N - 1; i >= 0; --i){
        froml[i] = max(ifleftatl[i], froml[i + 1]);
    }

    int ans = 0;
    rep(f, 0, N){
        ans = max(ans, ifleftatl[f] + froml[f + ifleftatl[f]]);
    }
    cout << ans << '\n';
    
    return 0;
}
