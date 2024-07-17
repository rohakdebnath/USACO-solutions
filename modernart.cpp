#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define cin read
#define cout written

struct Point
{
    int x;
    int y;
};

int main()
{
    ifstream read("art.in");
    ofstream written("art.out");

    int n; cin >> n;
    vector<vector<int>> art (n, vector<int> (n));
    set<int> colorsUsed;

    for (int i {0}; i < n; ++i)
    {
        string num; cin >> num;
        for (int j {0}; j < n; ++j)
        {
            int color = num[j] - '0';
            art[i][j] = color;
            colorsUsed.insert(color);
        }
    }

    for (int i {1}; i <= 9; ++i)
    {
        Point TR {0, n - 1};
        Point BL {n - 1, 0};

        for (int v {0}; v < n; ++v)
        {
            for (int h {0}; h < n; ++h)
            {
                if (art[v][h] == i)
                {
                    TR.x = max(h, TR.x);
                    TR.y = min(v, TR.y);
                    BL.x = min(h, BL.x);
                    BL.y = max(v, BL.y);
                }
            }
        }
        for (int v {TR.y}; v <= BL.y; ++v)
        {
            for (int h {BL.x}; h <= TR.x; ++h)
            {
                if (art[v][h] != i) colorsUsed.erase(art[v][h]);
            }
        }
    }

    colorsUsed.erase(0);

    cout << colorsUsed.size() << '\n';

    return 0;
}
