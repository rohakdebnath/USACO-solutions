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
    setIO("breedflip");
    int N; cin >> N;
    string A, B; cin >> A >> B;
    int i = 0;
    while (A[i] == B[i] and i < N) ++i;
    int ans = 0;
    while (i < N)
    {
        while (A[i] != B[i] and i < N) ++i;
        ++ans;
        while (A[i] == B[i] and i < N) ++i;
    }
    cout << ans << '\n';
    return 0;
}
