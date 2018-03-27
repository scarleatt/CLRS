#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int a[20]={-1,20,10,16,4,10,14,7,9,3,2,8,1};
int heap_size=12;
int swap(int a[],int i,int j) {
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int left(int i) {
    return 2*i;
}
int right(int i) {
    return 2*i+1;
}
int parent(int i) {
    return i/2;
}
void max_heapify(int i) {
    int l=left(i);
    int r=right(i);
    int largest;
    if (l<=heap_size && a[l]>a[i])
        largest=l;
    else largest=i;
    if (r<=heap_size && a[r]>a[largest])
        largest=r;
    if (largest!=i) {
        swap(a,largest,i);
        max_heapify(largest);
    }
}
void build_max_heap() {
    for (int i=heap_size/2;i>=1;i--)
        max_heapify(i);
}
void heapsort() {
    build_max_heap();
    for (int i=heap_size;i>=2;i--) {
        swap(a,1,i);
        heap_size--;
        max_heapify(1);
    }
}
int main() {
    heapsort();
    for (int i=1; i<=10; i++)
        cout<<a[i]<<" ";
    return 0;
}
