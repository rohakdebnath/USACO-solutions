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

struct Milk
{
    char c;
    int q;
};

int main()
{
    UNSYNC
    setIO("measurement");
    vector<pair<string, int>> log (101);
    int n; cin >> n;
    rep(0, n)
    {
        int day; cin >> day;
        string s; cin >> s;
        int chng; cin >> chng;
        log[day] = {s, chng};
    }
    vector<Milk> milk (3);
    milk[0].c = 'B'; milk[0].q = 7;
    milk[1].c = 'E'; milk[1].q = 7;
    milk[2].c = 'M'; milk[2].q = 7;

    int changes = 0;

    string ldb = "BEM";
    for (auto& d : log)
    {
        if (d.first == "") continue;
        if (d.first == "Bessie") milk[0].q += d.second;
        else if (d.first == "Elsie") milk[1].q += d.second;
        else milk[2].q +=d.second;

        vector<Milk> newMilk = milk;

        sort(all(newMilk), [](auto& x, auto& y) {return x.q > y.q;});
        
        vector<char> templdb = {newMilk[0].c};
        rep(1, 3)
        {
            if (newMilk[i].q == newMilk[i - 1].q) templdb.emplace_back(newMilk[i - 1].c);
            else break;
        }
        sort(all(templdb));
        
        string recon = "";
        for (char c: templdb) recon += c;

        if (recon != ldb) ++changes;
        ldb = recon;
    }

    cout << changes << '\n';
    
    return 0;
}
