//Implementation of the first idea that came into my mind, and as such the solution may not be the most optimal, yet I think the idea is pretty simple, If that could help even one person. Also, bits/stdc++.h suddenly stopped working on my Mac after Sonoma update and idk how to fix so sorry for the large headers. 
//Anyway, the approach is as follows: Observe the pattern that a gap of two in excitement level is observed only when an F is present in the ends.
//Explanation is provided on the internal implementation i think, just glossed over it. Next i make the max and min exciting strings and then print the possible excitement levels based on if F is present at the ends. I name the variables well so shouldnt be problem to follow this.
//max test case time limit is 48ms.

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

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    bool allF {true};
    for (int i {0}; i < n; ++i)
    {
        if (s[i] != 'F') allF = false;
    }

    if (allF)
    {
        cout << n << '\n';
        for (int i {0}; i < n; ++i)
        {
            cout << i << '\n';
        }
            return 0;
    }

    bool gapped {true};
    if (s[0] == 'F' or s[n - 1] == 'F') gapped = false;

    string smax {s};
    int maxAfterDecrypt {0};

    for (int i {0}; i < n - 1; ++i)
    {
        if ((smax[i] == 'E' or smax[i] == 'B') and smax[i + 1] == 'F') smax[i + 1] = smax[i];
    }

    for (int i {n - 1}; i > 0; --i) //backwards modification is necessary because consider a case like FFFBBEEF
    {
        if ((smax[i] == 'E' or smax[i] == 'B') and smax[i - 1] == 'F') smax[i - 1] = smax[i];
    }

    for (int i {1}; i < n; ++i)
    {
        if (smax[i] == smax[i - 1]) ++maxAfterDecrypt;
    }
    
    string smin {s};
    int minAfterDecrypt {0};

    for (int i {0}; i < n - 1; ++i)
    {
        if (smin[i] == 'E' and smin[i + 1] == 'F') smin[i + 1] = 'B';
        else if (smin[i] == 'B' and smin[i + 1] == 'F') smin[i + 1] = 'E';
    }

    for (int i {n - 1}; i > 0; --i)
    {
        if (smin[i] == 'E' and smin[i - 1] == 'F') smin[i - 1] = 'B';
        else if (smin[i] == 'B' and smin[i - 1] == 'F') smin[i - 1] = 'E';
    }

    for (int i {1}; i < n; ++i)
    {
        if (smin[i] == smin[i - 1]) ++minAfterDecrypt;
    }

    if (gapped)
    {
        cout << (maxAfterDecrypt - minAfterDecrypt)/2 + 1 << '\n';
        for (int i {minAfterDecrypt}; i <= maxAfterDecrypt; i += 2) cout << i << '\n';
    }
    else
    {
        cout << maxAfterDecrypt - minAfterDecrypt + 1 << '\n';
        for (int i {minAfterDecrypt}; i <= maxAfterDecrypt; ++i) cout << i << '\n';
    }
    return 0;
}
