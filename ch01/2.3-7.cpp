#include <iostream>
using namespace std;
int binary_search(int a[], int key, int len) {
    int low = 0, high = len;
    int mid = (low + high) / 2;
    if (a[mid] == key)
        return mid;
    else if (a[mid] > key)
        return mid - 1;
    else if (a[mid] < key)
        return mid + 1;
}
bool sum_to_x(int a[], int x, int len) {
    for (int i = 0; i < len; i++) {
        int pos = binary_search(a, x-a[i], len);
        if (pos<0) pos = 0;
        if (index && (a[i]+a[pos]==x))
            return true;
    }
    return false;
}
int main() {
    int a[8] = {5,2,4,6,1,3,9,8};
    int n = 8;
    cout<<sum_to_x(a, 10, n);
    return 0;
}