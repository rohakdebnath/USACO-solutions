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

struct Point
{
    int x;
    int y;
};

int N;

VVI shiftToTL(VVI& grid, Point& tl, Point& br)
{
    VVI tlGrid (N, VI (N));
    for (int i = tl.x; i <= br.x; ++i)
    {
        for (int j = tl.y; j <= br.y; ++j)
        {
            tlGrid[i - tl.x][j - tl.y] = (grid[i][j] == 1);
        }
    }
    return tlGrid;
}

VVI moveToij (VVI& grid, int i, int j)
{
    VVI newGrid (N, VI (N));
    for (int sx = i; sx < N; ++sx)
    {
        for (int sy = j; sy < N; ++sy)
        {
            newGrid[sx][sy] = (grid[sx - i][sy - j] == 1);
        }
    }
    return newGrid;
}

bool check(VVI& gridMain, VVI& grid1, VVI& grid2)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (gridMain[i][j] and !((grid1[i][j] and !grid2[i][j]) or (!grid1[i][j] and grid2[i][j]))) return false;
            else if (!gridMain[i][j] and (grid1[i][j] or grid2[i][j])) return false;
        }
    }
    return true;
}

int main()
{
    UNSYNC
    setIO("bcs");
    int K; cin >> N >> K;
    vector<VVI> grids (K + 1, VVI (N, VI (N)));

    vector<pair<Point, Point>> dim (K + 1);
    for (int i = 0; i <= K; ++i)
    {
        Point tl, br;
        tl.x = N - 1;
        tl.y = N - 1;
        br.x = 0;
        br.y = 0;
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                char c; cin >> c;
                if (c == '#')
                {
                    grids[i][j][k] = 1;
                    tl.x = min(tl.x, j);
                    tl.y = min(tl.y, k);
                    br.x = max(br.x, j);
                    br.y = max(br.y, k);
                }
            }
        }
        dim[i].first = tl;
        dim[i].second = br;
    }

    for (int i = 0; i <= K; ++i)
    {
        grids[i] = shiftToTL(grids[i], dim[i].first, dim[i].second);
    }
    
    for (int a = 1; a <= K; ++a)
    {
        for (int b = a + 1; b <= K; ++b)
        {
            //keep one same, move the other around
            for (int i = 0; i < N - dim[a].second.x + dim[a].first.x; ++i)
            {
                for (int j = 0; j < N - dim[a].second.y + dim[a].first.y; ++j)
                {
                    VVI newGrid = moveToij(grids[a], i, j);
                    bool result = check(grids[0], newGrid, grids[b]);
                    if (result)
                    {
                        cout << a << ' ' << b << '\n';
                        return 0;
                    }
                }
            }

            for (int i = 0; i < N - dim[b].second.x + dim[b].first.x; ++i)
            {
                for (int j = 0; j < N - dim[b].second.y + dim[b].first.y; ++j)
                {
                    VVI newGrid = moveToij(grids[b], i, j);
                    bool result = check(grids[0], newGrid, grids[a]);
                    if (result)
                    {
                        cout << a << ' ' << b << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
