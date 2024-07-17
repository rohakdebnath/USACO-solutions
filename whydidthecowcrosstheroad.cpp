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
    setIO("helpcross");
    int N, M; cin >> N >> M;
    VI C (N); rep(i, 0, N) cin >> C[i];
    vector<pair<int, int>> A (M); rep(i, 0, M) cin >> A[i].first >> A[i].second;
    sort(all(A));
    sort(all(C));

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int ans = 0;
    int j = 0;
    rep(i, 0, N){
        while (A[j].first <= C[i] and j < M){
            minHeap.push(A[j].second);
            ++j;
        }
        while (!minHeap.empty() and minHeap.top() < C[i]){
            minHeap.pop(); //once minHeap.top() is more than C[i], all other elements in the pq will also be greater than C[i]
        }
        if (!minHeap.empty()){
            minHeap.pop(); //popping this means that the two chickens which lets say had the same set of cows it could guide, wont be also to guide the same cow twice
            ++ans;
        }
    }
    cout << ans << '\n';
    return 0;
}
