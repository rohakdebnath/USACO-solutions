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

const int totcows {8};
vector<pair<string, string>> restrictions;
vector<bool> isitTaken (totcows, false);
const vector<string> COWS = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
bool found {false};
vector<string> lexicoArrangement;

void check(vector<string>& arrangement)
{
    bool survive = true;
    for (const auto& restriction : restrictions)
    {
        int index1 = distance(arrangement.begin(), find(all(arrangement), restriction.first));
        int index2 = distance(arrangement.begin(), find(all(arrangement), restriction.second));

        if (abs(index1 - index2) != 1) 
        {
            survive = false;
            break;
        }
    }

    if (survive)
    {
        found = true;
        for (const auto& cow : arrangement)
        {
            lexicoArrangement.emplace_back(cow);
        }
    }
}

void cowRec(vector<string> perm = {})
{
    if (found) return;
    if (perm.size() == totcows)
    {
        check(perm);
        return;
    }

    for (int i {0}; i < totcows; ++i)
    {
        if (isitTaken[i]) continue;
        isitTaken[i] = true;
        perm.emplace_back(COWS[i]);
        cowRec(perm);
        isitTaken[i] = false;
        perm.pop_back();
    }
}

int main()
{
    ifstream read("lineup.in");
    ofstream written("lineup.out");

    int N;
    cin >> N;
    restrictions.resize(N);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    rep1(N)
    {
        string s;
        getline(cin, s);
        
        restrictions[i] = {s.substr(0,s.find(' ')), s.substr(1 + s.rfind(' '))};
    }

    cowRec();

    for (const auto& cow : lexicoArrangement)
    {
        cout << cow << '\n';
    }
    return 0;
}
