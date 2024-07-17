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

struct Rectangle{
    int x1, y1, x2, y2;
};

Rectangle currect;
char grid[20][20];
bool vis[20][20];
int N, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void dfs(int i, int j, char c){
    rep(t, 0, 4){
        int ni = i + dx[t], nj = j + dy[t];
        if (vis[ni][nj] or ni < currect.x1 or ni > currect.x2 or nj < currect.y1 or nj > currect.y2 or grid[ni][nj] != c) continue;
        vis[ni][nj] = 1;
        dfs(ni, nj, c);
    }
}

int main()
{
    UNSYNC
    setIO("where");
    cin >> N;
    rep(i, 0, N){
        rep(j, 0, N){
            cin >> grid[i][j];
        }
    }
    vector<Rectangle> pcl;
    rep(x1, 0, N)
    rep(y1, 0, N)
    rep(x2, x1, N)
    rep(y2, y1, N){
        memset(vis, 0, sizeof(vis));
        currect = {x1, y1, x2, y2};
        map<char, int> freq;
        rep(x, x1, x2 + 1)
        rep(y, y1, y2 + 1){
            if (!vis[x][y]){
                vis[x][y] = 1;
                dfs(x, y, grid[x][y]);
                ++freq[grid[x][y]];
            }
        }
        if (freq.size() != 2) continue;
        auto it = freq.begin();
        int f1 = it -> second, f2 = (++it) -> second;
        if (f1 > f2) swap (f1, f2);
        if ((f1 == 1 and f2 > 1) or (f1 > 1 and f2 == 1)) pcl.push_back({x1, y1, x2, y2});
    }

    int ans = 0;
    rep(i, 0, pcl.size()){ //checks if rect i does not have any sub pcls or not
        bool srv = true;
        rep(j, 0, pcl.size()){
            if (i == j) continue;
            if (pcl[i].x1 >= pcl[j].x1 and pcl[i].x2 <= pcl[j].x2 and pcl[i].y1 >= pcl[j].y1 and pcl[i].y2 <= pcl[j].y2){
                srv = false;
                break;
            }
        }
        ans += srv;
    } 

    cout << ans << '\n';
    return 0;
}
