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

    vector<vector<char>> genes (2*N, vector<char> (M));
    for (int i {0}; i < 2*N; ++i)
    {
        for (int j {0}; j < M; ++j)
        {
            cin >> genes[i][j];
        }
    }

    vector<vector<int>> SC (N, vector<int> (M));
    vector<vector<int>> PC (2*N, vector<int> (M));
    vector<int> symbolMap (16*3 + 4*3 + 3 + 1); // formula for symbol id is 16i+4j+k for every ijk pair

    for (int i {0}; i < N; ++i)
        for (int j {0}; j < M; ++j)
        {
            if (genes[i][j] == 'A') SC[i][j] = 0;
            if (genes[i][j] == 'C') SC[i][j] = 1;
            if (genes[i][j] == 'G') SC[i][j] = 2;
            if (genes[i][j] == 'T') SC[i][j] = 3;
        }

    for (int i {N}; i < 2*N; ++i)
        for (int j {0}; j < M; ++j)
        {
            if (genes[i][j] == 'A') PC[i][j] = 0;
            if (genes[i][j] == 'C') PC[i][j] = 1;
            if (genes[i][j] == 'G') PC[i][j] = 2;
            if (genes[i][j] == 'T') PC[i][j] = 3;
        }

    bool flag {true};
    int triplets {0};
    for (int i {0}; i < M; ++i)
        for (int j {i + 1}; j < M; ++j)
        {
            for (int k {j + 1}; k < M; ++k)
            {
                for (int l {0}; l < N; ++l)
                {
                    symbolMap[16*SC[l][i] + 4*SC[l][j] + SC[l][k]] = 1;
                }
                for (int l {N}; l < 2*N; ++l)
                {
                    if (symbolMap[16*PC[l][i] + 4*PC[l][j] + PC[l][k]] == 1) flag = false;
                }

                if (flag) ++triplets;
                flag = true;
                for (int l {0}; l < N; ++l)
                {
                    symbolMap[16*SC[l][i] + 4*SC[l][j] + SC[l][k]] = 0;
                }
            }
        }
    cout << triplets << '\n';
    
    return 0;
}
