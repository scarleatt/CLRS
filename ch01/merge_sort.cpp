//不使用哨兵
#include <iostream>
using namespace std;
void merge(int a[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[p+i];
    for (int i = 0; i < n2; i++)
        R[i] = a[q+1+i];
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            a[k] = L[i]; i++;
            if (i >= n1) {
                for (int m = j; m < n2; m++) {
                    k++; a[k] = R[m];
                }
                break;
            }
        } else {
            a[k] = R[j]; j++;
            if (j >= n2) {
                for (int m = i; m < n1; m++) {
                    k++; a[k] = L[m];
                }
                break;
            }
        }
    }
}
void merge_sort(int a[], int p, int r) {
    if (p < r){
        int q = (p+r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}
int main() {
    int a[10] = {5,2,4,7,1,3,2,6};
    merge_sort(a, 0, 7);
    for (int i = 0; i < 8; i++)
        cout<<a[i]<<" ";
    return 0;
}

// #include <iostream>
// using namespace std;
// void merge(int a[], int p, int q, int r) {
//     int c1 = q-p+1;
//     int c2 = r-q;
//     int L[c1+1], R[c2+1];
//     for (int i = 0; i < c1; i++)
//         L[i] = a[p+i];
//     for (int i = 0; i < c2; i++)
//         R[i] = a[q+1+i];
//     L[c1] = INT_MAX;
//     R[c2] = INT_MAX;
//     int i = 0, j = 0;
//     for (int k = p; k <= r; k++) {
//         if (L[i] <= R[j]) {
//             a[k] = L[i];
//             i++;
//         } else {
//             a[k] = R[j];
//             j++;
//         }
//     }
// }
// void merge_sort(int a[], int p, int r) {
//     if (p < r) {
//         int q = (p+r)/2;
//         merge_sort(a, p, q);
//         merge_sort(a, q+1, r);
//         merge(a, p, q, r);
//     }
// }
// int main() {
//     int arr[7] = {5,2,4,6,3,12,2};
//     merge_sort(arr, 0, 6);
//     for (int i = 0; i < 7; i++)
//         cout<<arr[i]<<" ";
//     return 0;
// }