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
    setIO("div7");
    i64 N; cin >> N;
    VI ID (N); rep(i, 0, N) cin >> ID[i];
    VI pref (N); pref[0] = ID[0] % 7;
    VI firstoc (7, -1); firstoc[pref[0]] = 0;
    i64 maxi = 0;
    rep(i, 1, N)
    {
        pref[i] = (pref[i - 1] + ID[i]) % 7;
        if (firstoc[pref[i]] == -1) firstoc[pref[i]] = i;
        else maxi = max(maxi, i - firstoc[pref[i]]);
    }

    cout << maxi << '\n';
    return 0;
}
