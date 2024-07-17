#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
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

struct Bound
{
    int xl = 0;
    int yl = 0;
    int xu = 0;
    int yu = 0;
};

int barn[102][102];

int main()
{
    UNSYNC
    //setIO("paintbarn");
    int N, K; cin >> N >> K;
    rep(i, 0, N)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; ++x1, ++x2, ++y1, ++y2;
        ++barn[x1][y1];
        ++barn[x2][y2];
        --barn[x1][y2];
        --barn[x2][y1];
    }        

    int klayer = 0;
    rep(i, 1, 102)
    {
        rep(j, 1, 102)
        {
            barn[i][j] += barn[i - 1][j] + barn[i][j - 1] - barn[i - 1][j - 1];
            klayer += (barn[i][j] == K);
        }
    }
    Bound K;
    //nah this is way too long a question

    return 0;
}
