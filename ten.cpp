#include <bits/stdc++.h>
using namespace std;

struct Item { int v,w; };

int knapGreedy(int W, vector<Item> a) {
    sort(a.begin(), a.end(), [](Item x, Item y){
        return (double)x.v/x.w > (double)y.v/y.w;
    });
    int val = 0;
    for (auto &it : a) {
        if (it.w <= W) {
            W -= it.w;
            val += it.v;
        }
    }
    return val;
}

int knapDP(int W, vector<Item> &a) {
    int n = a.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1,0));
    for (int i = 1; i <= n; i++)
        for (int w = 0; w <= W; w++)
            if (a[i-1].w <= w)
                dp[i][w] = max(dp[i-1][w], a[i-1].v + dp[i-1][w - a[i-1].w]);
            else
                dp[i][w] = dp[i-1][w];
    return dp[n][W];
}

int knapBT(int i, int W, vector<Item> &a) {
    if (i == (int)a.size() || W == 0) return 0;
    if (a[i].w > W) return knapBT(i+1, W, a);
    int take = a[i].v + knapBT(i+1, W - a[i].w, a);
    int skip = knapBT(i+1, W, a);
    return max(take, skip);
}

int bestBB;

int bound(int i, int W, vector<Item> &a) {
    int n = a.size(), res = 0;
    for (int j = i; j < n; j++)
        if (a[j].w <= W) {
            W -= a[j].w;
            res += a[j].v;
        }
    return res;
}

void knapBB(int i, int W, int cur, vector<Item> &a) {
    if (i == (int)a.size() || W == 0) {
        bestBB = max(bestBB, cur);
        return;
    }
    if (cur + bound(i, W, a) <= bestBB) return;
    if (a[i].w <= W) knapBB(i+1, W - a[i].w, cur + a[i].v, a);
    knapBB(i+1, W, cur, a);
}

int main() {
    int W = 50;
    vector<Item> a = {{60,10},{100,20},{120,30}};
    cout << "Greedy: " << knapGreedy(W, a) << "\n";
    cout << "DP: " << knapDP(W, a) << "\n";
    cout << "Backtracking: " << knapBT(0, W, a) << "\n";
    bestBB = 0;
    knapBB(0, W, 0, a);
    cout << "Branch and Bound: " << bestBB << "\n";
}
