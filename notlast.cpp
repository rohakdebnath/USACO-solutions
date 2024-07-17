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
    ifstream read("notlast.in");
    ofstream written("notlast.out");

    map<string, int> milkLog {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}};
    int n;
    cin >> n;

    rep1(n)
    {
        string s;
        cin >> s;
        int m;
        cin >> m;

        milkLog[s] += m;
    }
    vector<pair<int, string>> cows;
	for (pair<string, int> t : milkLog) 
    { 
        cows.push_back({t.second, t.first});
    }
	sort(cows.begin(), cows.end());

    while (cows.size() > 1 and cows[0].first == cows[1].first)
    {
        cows.erase(cows.begin());
    }
    cows.erase(cows.begin());

    if (cows.size() == 0 or (cows.size() > 1 and cows[0].first == cows[1].first)) cout << "Tie\n";
    else cout << cows[0].second << '\n'; 
    return 0;
}
