#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)
#define cin read  
int main()
{
    ifstream read("hoofball.in");
    ofstream written("hoofball.out");

    int n; cin >> n;

    vector<int> positions (n);
    rep(0, n) {cin >> positions[i];}

    sort(all(positions));

    vector<int> ballsrecived (n);
    vector<int> ballpassedto (n);

    ++ballsrecived[1];
    ++ballsrecived[n - 2];
    ballpassedto[0] = 1;
    ballpassedto[n - 1] = n - 2;
    
    for (int i {1}; i < n - 1; ++i)
    {
        if (positions[i] - positions[i - 1] <= positions[i + 1] - positions[i])
        {
            ballpassedto[i] = i - 1;
            ++ballsrecived[i - 1];
        }
        else
        {
            ballpassedto[i] = i + 1;
            ++ballsrecived[i + 1];
        }
    }

    int isolatedCowPair {0};

    if(ballpassedto[2] != 1 and ballsrecived[0] == 1 and ballsrecived[1] == 1) ++isolatedCowPair;
    if(ballpassedto[n - 3] != n - 2 and ballsrecived[n - 1] == 1 and ballsrecived[n - 2] == 1) ++isolatedCowPair;

    for (int i {3}; i < n - 2; ++i)
    {
        if (ballsrecived[i - 1] == 1 and ballsrecived[i] == 1 and ballpassedto[i - 2] != i - 1 and ballpassedto[i + 1] != i) ++isolatedCowPair;
    }

    cout << count(all(ballsrecived), 0) + isolatedCowPair << '\n';

    return 0;
}
