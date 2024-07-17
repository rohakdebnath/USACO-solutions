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
    setIO("lifeguards");
    int N; cin >> N;
    vector<pair<int, int >> lf;
    rep(i, 0, N){
        int l, r; cin >> l >> r;
        lf.push_back({l, i});
        lf.push_back({r, i});
    }   
    sort(all(lf));
    set<int> workingguards;
    vector<int> alonework (N);
    int tot = 0, prev = 0;
    rep(i, 0, 2*N){
        int time = lf[i].first;
        int cowid = lf[i].second;
        if (!workingguards.empty()){
            tot += time - prev;
        }
        if (workingguards.size() == 1){
            alonework[*workingguards.begin()] += time - prev;
        }
        if (workingguards.find(cowid) != workingguards.end()){
            workingguards.erase(cowid);
        } else {
            workingguards.insert(cowid);
        }
        prev = time;
    }
    cout << tot - *min_element(all(alonework)) << '\n';
    return 0;
}
