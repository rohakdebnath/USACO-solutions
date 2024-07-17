#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

void solve()
{
    int N;
    cin >> N;

    vector<int> napTimes (N);
    int sum {0};

    rep1(N)
    { 
        cin >> napTimes[i];
        sum += napTimes[i];
    }

    if (sum == 0)
    {
        cout << 0 << '\n';
        return;
    }

    set<int> factor;
    for (int i {1}; i <= sqrt(sum); ++i)
    {
        if (sum % i == 0)
        {
            factor.insert(i);
            factor.insert(sum / i);
        }
    }

    for (const int& p : factor)
    {
        bool survive {true};
        for (int i {0}; i < N;)
        {
            int joinSum {0};
            while (joinSum < p and i < N)
            {
                joinSum += napTimes[i];
                ++i;
            }
            if (joinSum > p)
            {
                survive = false;
                break;
            }
        }
        if (survive)
        {
            cout << N - sum / p << '\n';
            break;
        }
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}
