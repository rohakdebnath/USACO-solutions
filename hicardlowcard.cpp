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
    setIO("cardgame");
    int N; cin >> N;
    set<int> B;
    rep(i, 1, 2*N + 1) B.insert(i);
    VI A (N); 
    rep(i, 0, N){
        cin >> A[i];
        B.erase(A[i]);
    } 
    int ans = 0;

    set<int> f;
    set<int> s;

    int t = 0;
    for(int c: B){
        if (t < N/2) s.insert(c);    
        else f.insert(c);
        ++t;
    }

    rep(i, 0, N/2){
        auto it = f.upper_bound(A[i]);
        if (it != f.end()){
            ++ans;
            f.erase(it);
        }
    }
    rep(i, N/2, N){
        auto it = s.upper_bound(A[i]);
        if (it != s.begin()){
            --it;
            ++ans;
            s.erase(it);
        }
    }

    cout << ans << '\n';    
    return 0;
}

