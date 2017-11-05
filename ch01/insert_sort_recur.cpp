#include <iostream>
using namespace std;
void insert(int a[], int j) {
    int i = j-1;
    int key = a[j];
    while (i>=0 && a[i]>key) {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = key;
    return;
}
void insert_sort(int a[], int j) {
    if (j > 0) {
        insert_sort(a, j-1);
        insert(a, j);
    } else return;
}
int main() {
    int n = 8;
    int a[8] = {5,2,4,6,1,3,9,8};
    insert_sort(a, 8);

    for (int i = 0; i < 8; i++)
        cout<<a[i]<<" ";
    return 0;
}