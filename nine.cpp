#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int main() {
    int n = 4;
    int g[4][4] = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    int d[4][4];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = g[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];

    cout << "All-pairs shortest paths:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (d[i][j] == INF) cout << "INF ";
            else cout << d[i][j] << " ";
        cout << "\n";
    }
}
