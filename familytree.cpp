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

int main()
{
    setIO("family");

    int n; cin >> n;
    string a, b; cin >> a >> b;
    map<string, vector<string>> momMap;
    map<string, string> momof;

    while (n--)
    {
        string mom, daughter; cin >> mom >> daughter;
        momof[daughter] = mom;
    }

    string curr = a;
    while (true)
    {
        momMap[a].emplace_back(curr);
        if (momof[curr] == "") break;
        curr = momof[curr];
    }
    
    curr = b;
    while (true)
    {
        momMap[b].emplace_back(curr);
        if (momof[curr] == "") break;
        curr = momof[curr];
    }

    string commonAncestor {""};
    for (string k : momMap[a])
    {
        if (find(all(momMap[b]), k) != momMap[b].end())
        {
            commonAncestor = k;
            break;
        }
    }
    if (commonAncestor == "")
    {
        cout << "NOT RELATED\n";
        return 0;
    }
    int level_a = distance(momMap[a].begin(), find(all(momMap[a]), commonAncestor));
    int level_b = distance(momMap[b].begin(), find(all(momMap[b]), commonAncestor));

    if (level_a > 1 and level_b > 1)
    {
        cout << "COUSINS\n";
        return 0;
    }

    if (level_a == level_b and level_a == 1)
    {
        cout << "SIBLINGS\n";
        return 0;
    }

    if (level_a == 0 or level_b == 0)
    {
        cout << (level_a < level_b ? a : b) << " is the ";
        for (int i {0}; i < max(level_a, level_b) - min(level_a, level_b) - 2; ++i) cout << "great-";
        if (max(level_a, level_b) - min(level_a, level_b) > 1) cout << "grand-";
        cout << "mother of " << (level_a < level_b ? b : a) << '\n';
        return 0;
    }

    if (level_a == 1 or level_b == 1)
    {
        cout << (level_a < level_b ? a : b) << " is the ";
        for (int i {0}; i < max(level_a, level_b) - min(level_a, level_b) - 1; ++i) cout << "great-";
        cout << "aunt of " << (level_a < level_b ? b : a) << '\n';
        return 0;
    }
    
    return 0;
}
