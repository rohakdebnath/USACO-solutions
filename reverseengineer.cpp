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

int N, M; 
vector<bool> used;
vector<string> strs;
vector<int> output;

bool checksame(int j, char comp, int out)
{
    if (used[j]) return false;

    rep(i, 0, M)
    {
        if (!strs[i].empty() and strs[i][j] == comp and !(output[i] == out)) return false;
    }
    rep(i, 0, M)
    {
        if (!strs[i].empty() and strs[i][j] == comp) strs[i] = "";
    }
    used[j] = true;
    return true;
}

bool allsame(int out)
{
    rep(i, 0, M)
    {
        if (!strs[i].empty() and output[i] != out) return false;
    }

    return true;
}

void solve()
{
    cin >> N >> M;
    used.resize(N);
    rep(i, 0, N) used[i] = false;
    strs.resize(M, "");
    output.resize(M, 0);
    rep(i, 0, M) cin >> strs[i] >> output[i];

    while (true)
    {
        bool splitfound = false;
        rep(i, 0, N)
        {
            if (checksame(i, '0', 0) or checksame(i, '0', 1) or checksame(i, '1', 0) or checksame(i, '1', 1)) splitfound = true;
        }

        if (!splitfound) 
        {
            cout << "LIE\n";
            return;
        }

        if (allsame(0) or allsame(1))
        {
            cout << "OK\n";
            return;
        }
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
