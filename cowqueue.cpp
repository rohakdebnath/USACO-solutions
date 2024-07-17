#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)
#define cin read
#define cout written

int main()
{
    ifstream read("cowqueue.in");
    ofstream written("cowqueue.out");

    int n;
    cin >> n;
    vector<pair<int, int>> cow (n);

    rep1(n){cin >> cow[i].first >> cow[i].second;}

    sort(all(cow));


    for (int i {1}; i < n; ++i)
    {
        if (cow[i-1].first + cow[i-1].second >= cow[i].first) cow[i].first = cow[i-1].first + cow[i-1].second;
    }

    cout << cow[n - 1].first + cow[n - 1].second << '\n';
    
    return 0;
}
