#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Write your solution here.
    int n, k; cin >> n >> k;
    vector<pair<int,int>> stuff;
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    for (int i = 0 ; i < n ; i++) {
        int w, v; cin >> w >> v;
        stuff.push_back({w, v});
    }

    for (int i = 1 ; i <= n ; i++) {
        auto [W, V] = stuff[i-1];

        for (int w = 0 ; w <= k ; w++) {
            if (w >= W) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-W] + V);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << dp[n][k] << '\n';


    return 0;
}
