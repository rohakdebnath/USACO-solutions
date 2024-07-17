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
    int N, X; cin >> N >> X;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));
    VI pfA (N); partial_sum(all(A), pfA.begin());
    cout << upper_bound(all(pfA), X) - pfA.begin() << '\n';
    return 0;
}
