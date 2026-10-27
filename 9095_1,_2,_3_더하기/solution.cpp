#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Write your solution here.
    int n; cin >> n;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int  j = 0 ; j < n ; j++) {
        int k; cin >> k;
        if (dp[k] != 0) {
            cout << dp[k] << '\n';
            continue;
        }
        for (int i = 4; i <= k ; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        cout << dp[k] << '\n';

    }

    return 0;
}
