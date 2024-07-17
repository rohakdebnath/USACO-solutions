#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep1(x) for (int i {0}; i < x; ++i)
#define rep2(x) for (int i {0}; i <= x; ++i)

int main()
{
    UNSYNC

    int N, M;
    cin >> N >> M;

    vector<vector<int>> conditioners (M, vector<int> (4));
    vector<int> stalls (100);

    rep1(N)
    {
        int s, t, c;
        cin >> s >> t >> c;

        for (int j {s - 1}; j < t; ++j)
        {
            stalls[j] = c;
        }
    }

    rep1(M)
    {
        cin >> conditioners[i][0] >> conditioners[i][1] >> conditioners[i][2] >> conditioners[i][3];
    }

    int minCost {INT32_MAX};

    for (int mask {0}; mask < (1 << M); ++mask)
    {
        int cost {0};
        vector<int> cooling (100, 0);
        for (int i {0}; i < M; ++i)
        {
            if (mask & (1 << i))
            {
                for (int c {conditioners[M - 1 - i][0] - 1}; c < conditioners[M - 1 - i][1]; ++c)
                {
                    cooling[c] += conditioners[M - 1 - i][2];
                }
                cost += conditioners[M - 1 - i][3];
            }
        }
        bool survive {true};
        for (int i {0}; i < 100; ++i)
        {
            if (cooling[i] < stalls[i])
            {
                survive = false;
                break;
            }
        }
        if (survive) minCost = min(minCost, cost);
    }

    cout << minCost << '\n';
    return 0;
}
