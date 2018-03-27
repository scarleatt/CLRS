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
int length=12;
int swap(int a[],int i,int j) {
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partition(int p,int r) {
    int x=a[r];
    int i=p-1;
    for (int j=p;j<=r-1;j++) {
        if (a[j]<x) {
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,r);
    return i+1;
}
int quicksort(int p,int r) {
    if (p<r) {
        int q=partition(p,r);
        quicksort(p,q-1);
        quicksort(q+1,r);
    }
}
int main() {
    quicksort(1,length);
    for (int i=1; i<=10; i++)
        cout<<a[i]<<" ";
    return 0;
}
