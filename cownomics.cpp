#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define cin read 
#define cout written

int main()
{
    ifstream read("cownomics.in");
    ofstream written("cownomics.out");

    int N, M;
    cin >> N >> M;

    vector<vector<char>> genome (2*N, vector<char> (M));

    for (int i {0}; i < 2*N; ++i)
    {
        for (int j {0}; j < M; ++j)
        {
            cin >> genome[i][j];
        }
    }
    int potentialGene {0};

    for (int i {0}; i < M; ++i)
    {
        vector<char> unique ;
        for (int j {N}; j < 2*N; ++j)
        {
            if (find(all(unique), genome[j][i]) == unique.end()) unique.emplace_back(genome[j][i]);
        }
        bool potent {true};
        for (int j {0}; j < N ; ++j)
        {
            for (char gene : unique)
            {
                if (gene == genome[j][i]) potent = false;
            }
        }
        if (potent) ++potentialGene;

    }
    cout << potentialGene << '\n';
    
    return 0;
}
