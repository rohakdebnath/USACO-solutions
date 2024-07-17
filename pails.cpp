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
    setIO("pails");
    int X, Y, M; cin >> X >> Y >> M;
    int maxMilk = 0;
    int LL = M/Y;
    int UL = M/X;
    for (int n = LL; n <= UL; ++n)
    {
        for (int i = 0; i <= n; ++i) if (i*X + (n - i)*Y <= M) maxMilk = max(maxMilk, i*X + (n - i)*Y);
    }

    cout << maxMilk << '\n';
    return 0;
}
