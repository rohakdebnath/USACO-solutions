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
    ifstream read("circlecross.in");
    ofstream written("circlecross.out");

    string s;
    cin >> s;

    int crossed {0};
    for (char i = 'A'; i <= 'Z'; ++i)
    {
        for (char j = i + 1; j <= 'Z'; ++j)
        {
            auto bi = find(all(s), i);
            auto ei = find(bi + 1, s.end(), i);
            auto bj = find(all(s), j);
            auto ej = find(bj + 1, s.end(), j);

            int dbi = distance(s.begin(), bi);
            int dei = distance(s.begin(), ei);
            int dbj = distance(s.begin(), bj);
            int dej = distance(s.begin(), ej);

            if ((dbj < dei and dbj > dbi and dei < dej) or (dbi < dej and dbi > dbj and dej < dei)) ++crossed;
        }
    }
    
    cout << crossed << '\n';
    return 0;
}
