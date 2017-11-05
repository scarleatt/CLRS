#include <iostream>
using namespace std;
int binary_search(int a[], int key, int len) {
    int low = 0, high = len;
    int mid = (low+high)/2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] > key)
        return mid-1;
    else if (a[mid] < key)
        return mid+1;
}
int insert_sort(int a[], int n) {
    int i, j;
    for (j = 1; j < n; j++) {
        int key = a[j];
        i = j-1;
        int pos = binary_search(a, key, i);
        if (pos<0) pos = 0;
        while (i>=pos && a[i]>key) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}
int main() {
    int a[8] = {5,2,4,6,1,3,9,8};
    int n = 8;
    insert_sort(a, n);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    return 0;
}