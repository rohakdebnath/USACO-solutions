//Three layers of binary search one for radius, one for position and an additional check for the index overall O(N(logN)^3)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<i64>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (i64 i = ini; i < x; ++i)
#define per(i, fin, x) for (i64 i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

i64 N;
VI bale;

i64 leftmost(i64 rad){
    i64 l = bale[0] - 1, r = bale[N - 1] + 1;
    while (r - l > 1){
        i64 currad = rad;
        i64 m = l + (r - l)/2;
        i64 reach = m + currad;
        int i = upper_bound(all(bale), reach) - bale.begin();
        while (reach < bale[N - 1] and i < N){
            currad -= 2;
            int newreach = bale[i - 1] + currad;
            if (newreach > reach) reach = newreach;
            else break;
            while(reach >= bale[i] and i < N) ++i;
        }
        if (reach < bale[N - 1]){
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

i64 rightmost(i64 rad){
    i64 l = bale[0] - 1, r = bale[N - 1] + 1;
    while (r - l > 1){
        i64 currad = rad;
        i64 m = l + (r - l)/2;
        i64 reach = m - currad;
        int i = lower_bound(all(bale), reach) - bale.begin();
        while (reach > bale[0] and i >= 0){
            currad -= 2;
            int newreach = bale[i] - currad;
            if (newreach < reach) reach = newreach;
            else break;
            while (i > 0 and reach <= bale[i - 1] and reach > bale[0]) --i;
        }
        if (reach <= bale[0]){
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main()
{
    UNSYNC
    // setIO("angry");
    cin >> N; bale.resize(N);
    rep(i, 0, N){
        i64 a; cin >> a;
        bale[i] = 2*a;
    }
    sort(all(bale));

    i64 lrad = -1, rrad = 1e9 + 1;
    while (rrad - lrad > 1){
        i64 m = lrad + (rrad - lrad)/2;
        i64 acreg = rightmost(m) - leftmost(m) + 1; //rightmost and leftmost points between which if bomb of radius m is dropped, will explode all the hays
        if (acreg < 0){
            lrad = m;
        } else {
            rrad = m;
        }
    }
    cout << fixed << setprecision(1) << rrad/2.0 << '\n';
    return 0;
}
