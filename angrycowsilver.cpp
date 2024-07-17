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
    setIO("angry");
    int N, K; cin >> N >> K;
    VI A (N); rep(i, 0, N) cin >> A[i];
    sort(all(A));

    int l = -1, r = 5e8 + 1; //best implementation of binary search, watch the last video of Pashka's binary search section on CF
    while (r - l > 1){
        int m = l + (r - l)/2;
        int last = 0;
        int bombsused = 0;
        int i = 0;
        while (last < A[N - 1] and i < N){
            last = A[i] + 2*m;
            ++bombsused;
            while (last >= A[i] and i < N) ++i;
        }
        if (bombsused > K){ //left point should point to falses as the distribution is of form FFFTTTT
            l = m;
        } else {
            r = m;
        }
    }
    cout << r << '\n';
    return 0;
}
