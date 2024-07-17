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
    setIO("diamond");
    int N, K; cin >> N >> K;
    VI sizes (N);
    rep(0, N) cin >> sizes[i];

    int maxSize = 0;
    for (int i : sizes)
    {
        int temp = 0;
        for (int j : sizes) if (i <= j and j <= i + K) ++temp;
        maxSize = max(maxSize, temp);
    }
    cout << maxSize << '\n';
    
    return 0;
}
