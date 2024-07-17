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
    setIO("pairup");
    int N; cin >> N;
    vector<pair<int, int>> cowp (N);
    rep(i, 0, N){
        cin >> cowp[i].first >> cowp[i].second;
    }
    sort(all(cowp), [] (auto& x, auto& y) {return x.second < y.second;});

    int maxy = 0;
    int j = N - 1;
    for(int i = 0; i <= j; ++i){
        maxy = max(maxy, cowp[i].second + cowp[j].second);
        while (j >= i and cowp[i].first >= cowp[j].first){
            int minf = min(cowp[i].first, cowp[j].first);
            cowp[i].first -= minf;
            --j;
        }
        if (j >= 0) cowp[j].first -= cowp[i].first;
    }
    cout << maxy << '\n';
    return 0;
}
