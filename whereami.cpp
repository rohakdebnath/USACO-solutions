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
    ifstream read("whereami.in");
    ofstream written("whereami.out");

    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i {1}; i <= n; ++i)
    {
        bool survive = true;
        map<string, int> substrfreq;
        for (int j {0}; j <= n - i; ++j)
        {
            ++substrfreq[s.substr(j,i)];
        }
        for (auto f : substrfreq)
        {
            if (f.second > 1)
            {
                survive = false;
                break;
            }
        }
        if (survive)
        {
            cout << i << '\n';
            return 0;
        }
    }
    return 0;
}
