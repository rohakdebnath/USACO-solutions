#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
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
    setIO("cbarn");
    int N; cin >> N;
    vector<int> barn (N);
    for(int& i : barn) cin >> i;

    int ans = INT32_MAX;

    for (int i = 0; i < N; ++i)
    {
        int tmpans = 0;
        for (int j = i; j < N + i; ++j) tmpans += (j - i) * barn[j % N];
        ans = min(ans, tmpans);
    }

    cout << ans << '\n';
    
    return 0;
}
