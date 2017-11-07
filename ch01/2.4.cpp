#include <iostream>
using namespace std;
void merge(int a[], int p, int q, int r, int& count) {
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++)
        L[i] = a[p+i];
    for (int i = 0; i < n2; i++)
        R[i] = a[q+i+1];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
            count++;
        }
    }
}
void merge_sort(int a[], int p, int r, int &count) {
    if (p < r) {
        int q = (p+r)/2;
        merge_sort(a, p, q, count);
        merge_sort(a, q+1, r, count);
        merge(a, p, q, r, count);
    } else return;
}


int main() {
    int a[8] = {5,2,4,6,1,3,9,8};
    int n = 8, count = 0;
    merge_sort(a, 0, 7, count);

    cout<<count<<endl;
    return 0;
}