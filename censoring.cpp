#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
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
    setIO("censor");
    string s, T; cin >> s >> T;
    int sz = T.size();
    string censored = "";
    for (char c : s)
    {
        censored += c;
        if (censored.size() >= sz and censored.substr(censored.size() - sz, sz) == T) censored.erase(censored.size() - sz, sz);
    }
    cout << censored << '\n';
    
    return 0;
}
