#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()

int main()
{
    UNSYNC

    ifstream read("gymnastics.in");
    ofstream written("gymnastics.out");

    int K, N;
    read >> K >> N;

    vector <vector<int>> positions (K, vector<int> (N));

    for (int i {0}; i < K; ++i)
    {
        for (int j {0}; j < N; ++j)
        {
            read >> positions[i][j];
        }
    }

    int consistentPairs {0};
    for (int i {0}; i < N; ++i)
    {
        for (int j {i + 1}; j < N; ++j)
        {
            int a {positions[0][i]};
            int b {positions[0][j]};
            bool consistent {true};
            for (int p {1}; p < K; ++p)
            {
                if (distance(positions[p].begin(), find(all(positions[p]), a)) > distance(positions[p].begin(), find(all(positions[p]), b)))
                {
                    consistent = false;
                }
            }
            if (consistent == true) ++consistentPairs;
        }
    }

    written << consistentPairs << '\n';

    return 0;
}
