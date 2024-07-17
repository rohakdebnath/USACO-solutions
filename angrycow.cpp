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

int n;
vector<int> hays;

int hayBlasts(int dir, int i) //idea is to determine furthest blasted hay and increase the radius from that hay, then keep at it unless no hay is found within a radius then sum all the hays from initial point to that point
{
    if (dir == 1)
    {
        int rad {1};
        int j;
        for (j = i; j < n;)
        {
            int k;
            for (k = j + 1; k < n; ++k)
            {
                if (hays[j] + rad >= hays[k]) continue;
                else break;
            }
            if (k - 1 > j)
            {
                j = k - 1;
                ++rad;
            }
            else break;
        }
        return j - i;
    }
    else
    {
        int rad {1};
        int j;
        for (j = i; j >= 0;)
        {
            int k;
            for (k = j - 1; k >= 0; --k)
            {
                if (hays[j] - rad <= hays[k]) continue;
                else break;
            }
            if (k + 1 < j)
            {
                j = k + 1;
                ++rad;
            }
            else break;
        }
        return i - j;
    }
}

int main()
{
    ifstream read("angry.in");
    ofstream written("angry.out");
    cin >> n;
    hays.resize(n);
    int maxBlast {1};

    rep1(n) {cin >> hays[i];}

    sort(all(hays));

    for (int i {0}; i < n; ++i)
    {
        maxBlast = max(maxBlast, hayBlasts(-1, i) + hayBlasts(1, i) + 1); // note that blasts directed towards one direction wont affect the other direction, so we can calc separately, +1 for the initial hay
    }

    cout << maxBlast << '\n';

    return 0;
}
