#include <iostream>
using namespace std;
int main() {
    int a[8] = {5,2,4,6,1,3,9,8};
    int n = 8;
    int i, j;
    for (j = 1; j < n; j++) {
        int key = a[j];
        i = j-1;
        int q = j/2;
        if (a[q] >= a[j]) {
            while (i>=q) {
                a[i+1] = a[i];
                i--;
            }
            if (a[q] != a[j]) {
                while (i>=0 && a[i]>key) {
                    a[i+1] = a[i];
                    i--;
                }
            }
            a[i+1] = key;
        } else {
            while (i>q && a[i]>key) {
                a[i+1] = a[i];
                i--;
            }
        }
        a[i+1] = key;
    }
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";

    return 0;
}