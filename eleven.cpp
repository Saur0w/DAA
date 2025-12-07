#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    double p[5] = {0,0.1,0.2,0.4,0.3};
    vector<vector<double>> e(n+2, vector<double>(n+2,0)), w(n+2, vector<double>(n+2,0));
    vector<vector<int>> root(n+2, vector<int>(n+2,0));

    for (int i = 1; i <= n+1; i++) {
        e[i][i-1] = 0;
        w[i][i-1] = 0;
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n-l+1; i++) {
            int j = i + l - 1;
            e[i][j] = 1e18;
            w[i][j] = w[i][j-1] + p[j];
            for (int r = i; r <= j; r++) {
                double t = e[i][r-1] + e[r+1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    cout << "Optimal cost: " << e[1][n] << "\nRoot: " << root[1][n] << "\n";
}
