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
    setIO("lazy");
    int N, K; cin >> N >> K;
    int rotN = 2*N - 1;
    VVI field (rotN, VI (rotN, -1)); //a negative instead of directly using zero is required to identify which spot to check on, note that -1 patches are not real and you cannot consider the cases where bessie is standing on such a point, the minus one can be easily taken care of by taking the maximum of the patch (when required) with 0.
    rep(i, 0, N)
    {
        rep(j, 0, N) cin >> field[i + j][N + j - i + 1]; //remember this formula (zero index 45 degree rotation)
    }

    VVI pref (rotN + 1, VI (rotN + 1)); // try to adapt the one based indexing for prefix sums
    rep(i, 1, rotN + 1) //for one based start loops from 1
    {
        rep(j, 1, rotN + 1)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + max(0, field[i - 1][j - 1]); //taken care of -1 by taking max with 0
        }
    }

    int maxi = 0;
    rep(i, K, rotN - K)
    {
        rep(j, K, rotN - K)
        {
            if (field[i][j] == -1) continue; //ignore when spot is not real
            maxi = max(maxi, pref[i + K + 1][j + K + 1] + pref[i - K][j - K] - pref[i + K + 1][j - K] - pref[i - K][j + K + 1]);// extra care must be taken as the prefix sum 2D array is one based while your normal fields vector is 0 based.
        }
    }

    if (K >= N) maxi = pref[rotN][rotN];

    cout << maxi << '\n';
    return 0;
}
