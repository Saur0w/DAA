//
// Created by sthap on 09-10-2025.
//

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
}

void insertionSort(int a[], int n) {
    for(int i=1; i<n; i++) {
        int k = a[i], j = i-1;
        while(j >= 0 && a[j] > k) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++) L[i] = a[l+i];
    for(int j=0; j<n2; j++) R[j] = a[m+1+j];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while(i<n1) a[k++] = L[i++];
    while(j<n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

int main() {
    cout << "Bubble Sort:     Best O(n)   | Avg O(n^2) | Worst O(n^2)\n";
    cout << "Insertion Sort:  Best O(n)   | Avg O(n^2) | Worst O(n^2)\n";
    cout << "Merge Sort:      Best O(nlogn) | Avg O(nlogn) | Worst O(nlogn)\n";

    int a[] = {12,11,13,5,6,7}, n = 6;
    mergeSort(a, 0, n-1);
    cout << "\nSorted: ";
    for(int i=0; i<n; i++) cout << a[i] << " ";
    return 0;
}
