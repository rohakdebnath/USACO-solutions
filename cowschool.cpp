#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    i64 n; cin >> n;
    vector<i64> v (n);
    for (i64& x : v) {cin >> x;}
    sort(all(v));

    i64 profit = 0;
    i64 tuition = 0;
    for (i64 i {0}; i < n; ++i)
    {
        if (v[i]*(n - i) > profit)
        {
            profit = v[i]*(n - i);
            tuition = v[i];
        }
    }
    cout << profit << ' ' << tuition << '\n';
    return 0;
}

