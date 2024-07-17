#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(ini, x) for (int i {ini}; i < x; ++i)

void setIO(string name = "")
{
    UNSYNC
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main()
{
    setIO("evolution");
    int n; cin >> n;
    map<string, vector<int>> populationsWithPower;
    map<string, bool> visited;
    vector<string> nop;

    for (int i {1}; i <= n; ++i)
    {
        int k; cin >> k;
        while (k--)
        {
            string s; cin >> s;
            populationsWithPower[s].emplace_back(i);
            if (!visited[s]) nop.emplace_back(s);
            visited[s] = true;
        }
    }

    for (int i {0}; i < nop.size(); ++i)
    {
        for (int j {i + 1}; j < nop.size(); ++j)
        {
            vector<int> pops {populationsWithPower[nop[i]]};
            pops.insert(pops.end(), all(populationsWithPower[nop[j]]));
            set<int> pop (all(pops));

            bool onlyInA {false};
            bool onlyInB {false};
            bool inBoth {false};

            for (int k : pop)
            {
                if (find(all(populationsWithPower[nop[i]]), k) != populationsWithPower[nop[i]].end() and find(all(populationsWithPower[nop[j]]), k) == populationsWithPower[nop[j]].end()) 
                {
                    onlyInA = true;
                    break;
                }
            }
            for (int k : pop)
            {
                if (find(all(populationsWithPower[nop[j]]), k) != populationsWithPower[nop[j]].end() and find(all(populationsWithPower[nop[i]]), k) == populationsWithPower[nop[i]].end()) 
                {
                    onlyInB = true;
                    break;
                }
            }
            for (int k : pop)
            {
                if (find(all(populationsWithPower[nop[j]]), k) != populationsWithPower[nop[j]].end() and find(all(populationsWithPower[nop[i]]), k) != populationsWithPower[nop[i]].end()) 
                {
                    inBoth = true;
                    break;
                }
            }

            if (onlyInA and onlyInB and inBoth)
            {
                cout << "no\n";
                return 0;
            }
        }
    }
    cout << "yes\n";
    
    return 0;
}
