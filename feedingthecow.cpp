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

void solve()
{
    int N, K; cin >> N >> K;
    string S; cin >> S;
    int count = 0;
    int hfed = - 1 - K, gfed = -K - 1;
    string fin (N, '.');
    rep(i, 0, N)
    {
        if (S[i] == 'H' and i > hfed + K)
        {
            ++count;
            hfed = i + K;
            if (i + K < N) fin[i + K] = 'H';
            else
            {
                if (fin[N - 1] == '.') fin[N - 1] = 'H';
                else if (fin[N - 2] == '.') fin[N - 2] = 'H';
            }
        }
        if (S[i] == 'G' and i > gfed + K)
        {
            ++count; 
            gfed = i + K;
            if (i + K < N) fin[i + K] = 'G';
            else
            {
                if (fin[N - 1] == '.') fin[N - 1] = 'G';
                else if (fin[N - 2] == '.') fin[N - 2] = 'G';
            }
        }
    }
    cout << count << '\n' << fin << '\n';
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
