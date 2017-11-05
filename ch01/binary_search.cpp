#include <iostream>
using namespace std;
void binary_search(int a[], int num, int p, int r) {
    if (p <= r) {
        int q = (p+r)/2;
        if (a[q] == num)
            cout<<q<<endl;
        else if (a[q] > num)
            binary_search(a, num, p, q-1);
        else if (a[q] < num)
            binary_search(a, num, q+1, r);
    }
}
int main() {
    int a[8] = {1,2,3,4,5,6,7,8};
    binary_search(a, 5, 0, 7);

    return 0;
}