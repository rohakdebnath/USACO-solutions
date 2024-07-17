#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define Unsync ios::sync_with_stdio(false); cin.tie(nullptr);
#define sz(x) static_cast<int>((x).size())
#define all(x) x.begin(), x.end()

int main()
{
    ifstream read("blocks.in");
	ofstream written("blocks.out");

    Unsync
    int panels;
    read >> panels;
    
    vector<string> front(panels);
    vector<string> back(panels);
    
    for (int i {0}; i < panels; ++i)
    {
        read >> front[i] >> back[i];
    }

    vector<int> occurances(26, 0);

    for (char c {'a'}; c <= 'z'; c++)
    {
        for (int j = 0; j < panels; j++)
        {
            occurances[c - 'a'] += max(count(all(front[j]), c), count(all(back[j]), c));
        }   
    }

    for (int i : occurances) written << i << '\n';
    
    return 0;
}
