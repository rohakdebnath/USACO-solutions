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

int canvas[1001][1001];
int prefs [1001][1001];

int main()
{
    UNSYNC
    //setIO("art");
    int n; cin >> n;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            int k; cin >> k;
            canvas[i + 1][j + 1] = k;
        }
    }
    
    
    return 0;
}
