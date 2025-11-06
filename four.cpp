//
// Created by sthap on 02-11-2025.
//

#include <iostream>
using namespace std;

int maxElement(int a[], int l, int r, int th = 5) {
    if(r - l + 1 <= th) {
        int mx = a[l];
        for(int i=l+1; i<=r; i++)
            if(a[i] > mx) mx = a[i];
        return mx;
    }
    int m = (l+r)/2;
    return max(maxElement(a, l, m, th), maxElement(a, m+1, r, th));
}

int search(int a[], int l, int r, int k, int th = 5) {
    if(r - l + 1 <= th) {
        for(int i=l; i<=r; i++)
            if(a[i] == k) return i;
        return -1;
    }
    int m = l + (r-l)/2;
    if(a[m] == k) return m;
    return a[m] > k ? search(a, l, m-1, k, th) : search(a, m+1, r, k, th);
}

int main() {
    int a[] = {3,41,52,26,38,57,9,49}, n = 8;
    cout << "Max Element: " << maxElement(a, 0, n-1) << endl;

    int b[] = {2,5,8,12,16,23,38,45,56,67}, m = 10;
    cout << "Search 23: Index " << search(b, 0, m-1, 23) << endl;

    return 0;
}
