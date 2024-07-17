#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);

int ans = 0;
vector<int> tree[100000];
void dfs(int s, int p){
    int powt = 2;
    int pw = 0;
    while (tree[s].size() + (p == -1) > pow(powt, pw)) ++pw;
    ans += pw;
    for (int u: tree[s]){
        if (u != p) dfs(u, s);
    }
}

int main()
{
    UNSYNC
    int N; cin >> N;
    ans += N - 1;
    for (int i = 0; i < N - 1; ++i){
        int x, y; cin >> x >> y;
        --x, --y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(0, -1);

    cout << ans << '\n';
    return 0;
}
