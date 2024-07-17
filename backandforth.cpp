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

vector<int> storage (2, 1000);
vector<vector<int>> buckets (2, vector<int> (10));
set<int> variation;

void backforthRec(int n = 0)
{
    if (n == 4)
    {
        variation.insert(storage[n%2]);
        return;
    }
    for (int i {0}; i < buckets[n%2].size(); ++i)
    {
        storage[n%2] -= buckets[n%2][i];
        storage[(n + 1)%2] += buckets[n%2][i];
        int removedBucket {buckets[n%2][i]};
        buckets[n%2].erase(buckets[n%2].begin() + i);
        buckets[(n + 1)%2].emplace_back(removedBucket);

        backforthRec(n + 1);

        buckets[n%2].insert(buckets[n%2].begin() + i, removedBucket);
        buckets[(n + 1)%2].pop_back();
        storage[n%2] += buckets[n%2][i];
        storage[(n + 1)%2] -= buckets[n%2][i];
    }

}

int main()
{
    ifstream cin("backforth.in");
    ofstream cout("backforth.out");

    for (int i {0}; i < 2; ++i)
    {
        for (int j {0}; j < 10; ++j) cin >> buckets[i][j];
    }

    backforthRec();

    cout << variation.size() << '\n';
    
    return 0;
}
