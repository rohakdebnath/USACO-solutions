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
    setIO("lemonade");
    int N; cin >> N;
    VI w (N); rep(i, 0, N) cin >> w[i];
    sort(all(w), greater<int> ());
    int i = 0;
    int ans = 0;
    while (i < N){
        if (i <= w[i]){
            ++ans;
            ++i;
        } else {
            break;
        }
    }
    cout << ans << '\n';
    
    return 0;
}
