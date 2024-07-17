#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
pair<int, int> A, B;

int nex(int x)
{
    if (A.first <= x and x <= A.second) x = A.first + A.second - x;
    if (B.first <= x and x <= B.second) x = B.first + B.second - x;
    return x;
}

int main()
{
    setIO("swap");

    int n, k; cin >> n >> k;
    vector<int> order (n);
    cin >> A.first >> A.second >> B.first >> B.second;

    for (int i {1}; i <= n; ++i)
    {
        int per {1};
        int curr = nex(i);

        while (curr != i)
        {
            ++per;
            curr = nex(curr);
        }
        int kn = k % per;
        while (kn--) curr = nex(curr);

        order[curr - 1] = i;
    }

    for (int i : order) cout << i << '\n';
    return 0;
}
