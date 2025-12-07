#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int n = 4;
int distMat[4][4] = {
    {0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}
};
int bestCost = INF;
bool used[10];

void tspBT(int pos, int cnt, int cost) {
    if (cnt == n) {
        bestCost = min(bestCost, cost + distMat[pos][0]);
        return;
    }
    for (int i = 0; i < n; i++) if (!used[i]) {
        used[i] = 1;
        tspBT(i, cnt+1, cost + distMat[pos][i]);
        used[i] = 0;
    }
}

int main() {
    used[0] = 1;
    tspBT(0, 1, 0);
    cout << "TSP Backtracking cost: " << bestCost << "\n";
}
