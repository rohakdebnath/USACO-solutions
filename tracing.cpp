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

int main()
{
    ifstream read("tracing.in");
    ofstream written("tracing.out");

    int N, T;
    cin >> N >> T;
    string oriS;
    cin >> oriS;

    map<int, vector<int>> timestamps;   //Im using a map because it will order the Hoofshakes according to time automatically
    rep1(T)
    {
        int time ;
        vector<int> shakePair (2);

        cin >> time >> shakePair[0] >> shakePair[1];

        timestamps[time] = shakePair;
    }

    vector<int> rangeK;
    vector<int> patientZeros (N, 0); // this is essentially to flag if a cow can be a patient, initially everyone is guilt free

    for (int i {0}; i < N; ++i) // ill consider a cow to be patient zero and run a loop for k from 0 to total shakes for each cow and see if final condition of cows matches original condition
    {
        for (int k {0}; k <= T; ++k)
        {
            string ini (N, '0');
            ini[i] = '1';
            vector<int> K (N); // this is to hold the k's the cows are having currently
            K[i] = k; 
            for (auto& pair : timestamps) // after a shake a cowvidless cow becomes a '1' and gets a counter 'k' signifying the shakes left before it washes its hoofs
            {                             // a cowvidful cow will get --k after a shake with whoever
                vector<int> oneShake = pair.second; // auto deduces to std::pair 
                if (ini[oneShake[0] - 1] == '1' and K[oneShake[0] - 1] and ini[oneShake[1] - 1] == '0')
                {
                    ini[oneShake[1] - 1] = '1';
                    --K[oneShake[0] - 1];
                    K[oneShake[1] - 1] = k;
                }

                else if (ini[oneShake[0] - 1] == '0' and K[oneShake[1] - 1] and ini[oneShake[1] - 1] == '1')
                {
                    ini[oneShake[0] - 1] = '1';
                    --K[oneShake[1] - 1];
                    K[oneShake[0] - 1] = k;
                }

                else if (ini[oneShake[0] - 1] == '1' and ini[oneShake[1] - 1] == '1' and (K[oneShake[0] - 1] or K[oneShake[1] - 1]))
                {
                    if (K[oneShake[0] - 1]) --K[oneShake[0] - 1];
                    if (K[oneShake[1] - 1]) --K[oneShake[1] - 1];
                }
            }
            if (ini  == oriS)
            {
                rangeK.emplace_back(k);
                if (patientZeros[i] == 0) patientZeros[i] = 1;
            } 
        }
    }

    cout << accumulate(all(patientZeros), 0) << ' ';
    cout << *min_element(all(rangeK)) << ' ';
    if (find(all(rangeK), T) != rangeK.end()) cout << "Infinity\n";  //If we can find a k which is equal to the no. of shakes then essentially if the k was higher we would never know
    else cout << *max_element(all(rangeK)) << '\n';
    
    return 0;
}
