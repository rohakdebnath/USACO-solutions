#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define VI vector<int>
#define VVI vector<vector<int>>

int main()
{
    UNSYNC
    int n; cin >> n;
    vector<pair<int, int>> N;
    vector<pair<int, int>> E;
    vector<int> ini (n);
    unordered_map<int, int> status;
    rep(0, n)
    {
        char s; cin >> s;
        int x, y; cin >> x >> y;

        ini[i] = x;
        status[x] = -1;
        if (s == 'N') N.emplace_back(make_pair(x, y));
        else E.emplace_back(make_pair(x, y));
    }

    sort(all(N));
    sort(all(E), [](const auto& p1, const auto& p2) {return p1.second < p2.second;});

    for (auto i : E)
    {
        for (auto j : N)
        {
            if (status[j.first] != -1) continue; //we skip it because these j's (North directed cows) are already stopped by a path
            if (i.second > j.second and i.first < j.first)
            {
                int dx = j.first - i.first;
                int dy = i.second - j.second;
                if (dx > dy)
                {
                    status[i.first] = dx;
                    break;
                }
                else if (dx < dy)
                {
                    status[j.first] = dy;
                }
            }
        }
    }

    for (int i : ini)
    {
        if (status[i] == -1) cout << "Infinity\n";
        else cout << status[i] << '\n';
    }
    return 0;
}
