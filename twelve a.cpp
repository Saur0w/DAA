#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int main() {
    int n = 4;
    int dist[4][4] = {
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };

    int N = 1<<n;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) if (mask & (1<<u)) {
            for (int v = 0; v < n; v++) if (!(mask & (1<<v))) {
                dp[mask | (1<<v)][v] = min(dp[mask | (1<<v)][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INF;
    for (int u = 0; u < n; u++)
        ans = min(ans, dp[N-1][u] + dist[u][0]);

    cout << "TSP DP cost: " << ans << "\n";
}
