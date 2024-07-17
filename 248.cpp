#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    string name = "248";
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) { 
		cin >> a[i]; 
	}
	vector<vector<int>> dp(n, vector<int>(n, -1));  
    // dp[i][j] = final element the range i..j can  
	// be merged into as a single element, -1 if it	 
	// cannot be merged into a single element				                   
	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j) {
			if (i == j) {
				dp[i][j] = a[i];
			} else {
				for (int k = i; k < j; ++k) {
					if (dp[i][k] != -1 and dp[i][k] == dp[k + 1][j]) {
						dp[i][j] = dp[i][k] + 1;
					}
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}
