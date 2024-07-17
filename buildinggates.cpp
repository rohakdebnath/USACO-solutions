//Two things, what is going on and why we are multiplying by two.
//One, Imagie you have a large field, FJ puts fences. Our task is to calculate the different regions, for that imagine filling a particular region with flood (kinda like MS paint if you are old enough to remember), this flood will reach wherever it can go, the amount of times you have to fill the field with flood is the number of regions there are.
//Second, Imagine something like this:
//##
//## and the fence was made by NESW, filling the flood in this region will not work since this is treated as a single lump of fence, but we know in reality the fences do have space in between,
//Simply multiplying all the fence steps by two solves the problem. NESW now produces:
//###
//#.#
//### which correctly depicts the situation (credit: lam nguyen)

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

int N;
bool fence[4003][4003]; //centred at 2000, 2000 each on both sides making it 4001 and an extra 2 to represent the open field
bool vis[4003][4003];
int minx = 4001, miny = 4001, maxx = 0, maxy = 0; //The region I have made is centred at 2000, 2000

void dfs(int i, int j){
    if (i < minx or i > maxx or j < miny or j > maxy or fence[i][j] or vis[i][j]) return;
    vis[i][j] = 1;
    int x[] = {-1, 0, 0, 1}, y[] = {0, -1, 1, 0};
    rep(k, 0, 4){
        dfs(i + x[k], j + y[k]);
    }
}

int main()
{
    UNSYNC
    setIO("gates");
    cin >> N;
    string S; cin >> S;
    map<char, pair<int, int>> dir;
    dir['N'] = {0, 1};   
    dir['E'] = {1, 0};    
    dir['W'] = {-1, 0};    
    dir['S'] = {0, -1};    
    int x = 2000, y = 2000; //2000, 2000 is the centre of the region

    for (char d: S){
        fence[x + dir[d].first][y + dir[d].second] = 1;
        fence[x + 2*dir[d].first][y + 2*dir[d].second] = 1;
        x += 2*dir[d].first;
        y += 2*dir[d].second;
        minx = min(minx, x);
		maxx = max(maxx, x);
		miny = min(miny, y);
		maxy = max(maxy, y); //for faster solution we calculate the net fence rectangle, this is not strictly necessary but it will reudce the time for most cases if you have the correct implementation.
    }
    --minx, ++maxx, --miny, ++maxy; //if you include a boundary on our fence rectangle, we will definitely include the open field as a region too

    int regions = 0;
    rep(i, minx, maxx + 1){
        rep(j, miny, maxy + 1){
            if (!vis[i][j] and !fence[i][j]){

                dfs(i, j);
                ++regions;
            }
        }
    }
    
    cout << regions - 1 << '\n'; //the each "closed" region will correspond to a gate and -1 for the open ground, or you can think of it like, each gate connects two regions (when i say region i include the open ground too), thus regions - 1.
    return 0;
}
