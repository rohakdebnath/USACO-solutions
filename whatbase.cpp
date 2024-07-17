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

int value(int a, int base)
{
    return a/100*base*base + (a/10)%10*base + a%10;
}

void solve()
{
    int a, b; cin >> a >> b;
    int x = 10, y = 10;
    int vala = value(a, x);
    int valb = value(b, y);

    while (vala != valb)
    {
        if (vala > valb)
        {
            ++y;
            valb = value(b, y);
        }
        else
        {
            ++x;
            vala = value(a, x);
        }
    }
    cout << x << ' ' << y << '\n';
}

int main()
{
    setIO("whatbase");
    int T; cin >> T;
    while( T--) solve();
    
    return 0;
}
