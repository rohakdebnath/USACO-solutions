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

int main()
{
    UNSYNC
    int N, K; cin >> N >> K;
    VI seeding (N);
    rep(i, 0, K)
    {
        int l, r; cin >> l >> r;
        ++seeding[l - 1];
        --seeding[r];
    }
    VI haystack (N); haystack[0] = seeding[0];
    rep(i, 1, N) haystack[i] = haystack[i - 1] + seeding[i];
    sort(all(haystack));
    cout << haystack[(N - 1)/2] << '\n';
    return 0;
}
