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

vector<string> Cyear = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
struct Rel
{
    string name;
    bool prev;
    int year;
    string relative;
};

int mod(int a, int b)
{
    return ((a % b) + b) % b;
}

int main()
{
    int n; cin >> n;
    vector<Rel> relations (n);

    for (Rel& r: relations)
    {
        string sense;
        string trash;
        string relative;
        string animal;
        cin >> r.name >> trash >> trash >> sense >> animal >> trash >> trash >> r.relative;
        r.year = find(all(Cyear), animal) - Cyear.begin();
        r.prev = sense == "previous";
    }

    unordered_map<string, int> birthYear {{"Bessie", 0}};

    for (Rel& r: relations)
    {
        int change = r.prev ? -1 : 1;
        int year = birthYear[r.relative] + change;
        while (mod(year, 12) != r.year) year += change;

        birthYear[r.name] = year;
    }
    cout << abs(birthYear["Elsie"])  << '\n';
    return 0;
}
