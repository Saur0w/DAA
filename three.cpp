//
// Created by sthap on 09-10-2025.
//

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void quickSort(int a[], int l, int h) {
    if(l < h) {
        int p = a[h], i = l-1;
        for(int j=l; j<h; j++) {
            if(a[j] < p) swap(a[++i], a[j]);
        }
        swap(a[i+1], a[h]);
        int pi = i+1;
        quickSort(a, l, pi-1);
        quickSort(a, pi+1, h);
    }
}

void externalSort(string in, string out) {
    ifstream inf(in);
    int a[1000], n = 0;
    while(inf >> a[n] && n < 1000) n++;
    inf.close();

    quickSort(a, 0, n-1);

    ofstream outf(out);
    for(int i=0; i<n; i++) outf << a[i] << " ";
    outf.close();
}

int main() {
    int a[100];
    for(int i=0; i<100; i++) a[i] = rand()%1000;

    clock_t s = clock();
    quickSort(a, 0, 99);
    cout << "Internal Sort: " << (clock()-s)*1000.0/CLOCKS_PER_SEC << "ms\n";

    ofstream f("data.txt");
    for(int i=0; i<100; i++) f << rand()%1000 << " ";
    f.close();

    s = clock();
    externalSort("data.txt", "sorted.txt");
    cout << "External Sort: " << (clock()-s)*1000.0/CLOCKS_PER_SEC << "ms\n";

    return 0;
}
