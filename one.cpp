//
// Created by sthap on 09-10-2025.
//

#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x, int &c) {
    c++;
    if (l > r) return -1;
    int m = l + (r - l) / 2;
    if (arr[m] == x) return m;
    return arr[m] > x ? binarySearch(arr, l, m-1, x, c) : binarySearch(arr, m+1, r, x, c);
}

int fib(int n, int &c) {
    c++;
    return (n <= 1) ? n : fib(n-1, c) + fib(n-2, c);
}

int main() {
    int arr[] = {1,3,5,7,9,11,13,15}, n = 8, c1 = 0, c2 = 0;

    binarySearch(arr, 0, n-1, 7, c1);
    cout << "Binary Search calls: " << c1 << " | T(n) = T(n/2) + 1 -> O(log n)\n";

    fib(10, c2);
    cout << "Fibonacci calls: " << c2 << " | T(n) = T(n-1) + T(n-2) + 1 -> O(2^n)\n";

    return 0;
}

