#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[301][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Write your solution here.

    int n; cin >> n;
    vector<int> weight(n+1, 0);
    for (int i = 1 ; i <= n ; i++) {
        int w ; cin >> w;
        weight[i] = w;
    }
    dp[1][1] = weight[1];
    dp[2][1] = weight[2];
    dp[2][2] = weight[1] + weight[2];

    for (int i = 3 ; i <= n ; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + weight[i];
        dp[i][2] = dp[i-1][1] + weight[i];
    }

    cout << max(dp[n][1], dp[n][2]) << '\n';

    return 0;
}
