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
    setIO("berries");
    int N, K; cin >> N >> K;
    priority_queue<int> berrytree;
    rep(i, 0, N){
        int b; cin >> b;
        berrytree.push(b);
    }
    int ans = 0;
    rep(x, 0, 1001){
        priority_queue<int> pq = berrytree;
        if (x > pq.top()) continue;
        rep(i, 0, K/2){
            int newv = pq.top() - x;
            pq.pop();
            pq.push(newv);
        }
        int curans = 0;
        rep(i, 0, K/2){
            curans += min(x, pq.top());
            int newv = pq.top() - min(x, pq.top());
            pq.pop();
            pq.push(newv);
        }
        ans = max(ans, curans);
    }
    cout << ans << '\n';
    return 0;
}
