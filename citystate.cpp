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
    ifstream read("citystate.in");
    ofstream written("citystate.out");
    
    int n;
    cin >> n;

    vector<pair<string, string>> cityState;

    rep1(n)
    {
        string city, state;
        cin >> city >> state;
        city = city.substr(0,2);
        cityState.push_back({city, state});
    }

    unordered_map<string, int> seen;
    int specialPairs (0);

    for (const auto& [c, s] : cityState)
    {
        ++seen[c + s]; 
        if (c != s) specialPairs += seen[s + c];
    }

    cout << specialPairs << '\n';

    return 0;
}
