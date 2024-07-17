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
    setIO("badmilk");
    int N, M, D, S; cin >> N >> M >> D >> S;
    VVI FDT (M + 1, VI (N + 1, 101));
    rep(0, D)
    {
        int p, m, t; cin >> p >> m >> t;
        FDT[m][p] = min(FDT[m][p], t);
    }
    VI ST (N + 1, 999);
    rep(0, S)
    {
        int p, t; cin >> p >> t;
        ST[p] = t;
    }
    int allMeds = 0;
    for (int m = 1; m <= M; ++m)
    {
        bool survive = true;
        for(int p = 1; p <= N; ++p)
        {
            if (ST[p] <= FDT[m][p])
            {
                survive = false;
                break;
            }
        }
        int currMeds = 0;
        if (survive)
        {
            for (int p = 0; p <= N; ++p) if (FDT[m][p] < 101) ++currMeds;
            allMeds = max(allMeds, currMeds);
        }
    }

    cout << allMeds << '\n';
    
    return 0;
}
