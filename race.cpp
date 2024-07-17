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
#define cin read
#define cout written


int sumTill(int p)
{
    return p*(p+1)/2;
}

int main()
{
    ifstream read("race.in");
    ofstream written("race.out");

    i64 k, n; 
    cin >> k >> n;

    while (n--)
    {
        i64 x; cin >> x;
        i64 maxSpeed = ceil(((sqrt(8*k + 1LL) - 1LL)/2));
        if (x >= maxSpeed)
        {
            cout << maxSpeed << '\n';
            continue;
        }
        else
        {
            i64 extra {x - 1};
            i64 maxLimitedSpeed = floor(sqrt(k + sumTill(extra)));
            i64 time {2*maxLimitedSpeed - 1 - extra};
            i64 distanceTravelled {maxLimitedSpeed*maxLimitedSpeed - sumTill(extra)};

            while (distanceTravelled < k)
            {
                distanceTravelled += maxLimitedSpeed;
                ++time;
            }
            cout << time << '\n';
        }
    }
    
    return 0;
}
