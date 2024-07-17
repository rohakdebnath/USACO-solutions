#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)

int main()
{
    ifstream cin("lineup.in");
    ofstream cout("lineup.out");
    const vector<string> COWS = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    map<string, int> cowIndex;

    rep(0, COWS.size()) cowIndex[COWS[i]] = i;

    vector<vector<int>> adjList (COWS.size());
    vector<bool> placed (COWS.size());
    vector<int> order;

    int N; cin >> N;
    rep(0, N)
    {
        string cow1, cow2, trash;
        cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;
        int c1 = cowIndex[cow1];
        int c2 = cowIndex[cow2];

        adjList[c1].emplace_back(c2);
        adjList[c2].emplace_back(c1);
    }

    rep(0, COWS.size())
    {
        if (!placed[i] and adjList[i].size() <= 1) //start of a group (chain) if 1, individual if 0
        {
            placed[i] = true; //place it either if it has one or zero neighbours
            order.emplace_back(i);

            if (adjList[i].size() == 1) //if it has exactly one neighbour then check if the *neihbour* has one or two neighbours (only possibility)
            {
                int prev = i; //first place the neighbour
                int curr = adjList[i][0]; 
                while (adjList[curr].size() == 2) //check if this neighbour has 2 neighbours or not, one of this must be the original cow
                {
                    placed[curr] = true; // place it and know more about its neighbours
                    order.emplace_back(curr);

                    int a = adjList[curr][0];
                    int b = adjList[curr][1];

                    int tempCurr = a == prev ? b : a; // now ill know more about the neighbour other than the original cow, if it again has 2 neighbours it runs thr loop again
                    prev = curr;
                    curr = tempCurr;
                }// our goal is to detect a chain and place all the cows as we encounter them in the chain
                //the chain will automatically terminate when the "curr" cow has only one neighbour (only neighbour is prev), in which case we continue the iteration of the outer loop
                placed[curr] = true;
                order.emplace_back(curr);
            }
        }
    }

    for (int i : order) cout << COWS[i] << '\n';
    return 0;
}
