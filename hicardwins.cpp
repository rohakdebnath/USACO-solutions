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
    setIO("highcard");
    int N; cin >> N;
    set<int> Bes;
    rep(i, 1, 2*N + 1) Bes.insert(i);
    VI E (N); 
    rep(i, 0, N){
        cin >> E[i];
        Bes.erase(E[i]);
    } 
    VI B (all(Bes));
    sort(all(E));

    int ans = 0;
    int j = 0;
    rep(i, 0, N){
        while (j < N and E[i] > B[j]) ++j;
        if (j == N) break;
        ++ans;
        ++j;
    }

    cout << ans << '\n';
    return 0;
}
