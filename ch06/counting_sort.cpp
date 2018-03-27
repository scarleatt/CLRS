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
int a[20]={20,10,16,4,10,14,7,9,3,2,8,1};
int length=12;
void counting_sort() {
    int max_n=max(a[0],a[length]);
    int res[max_n];
    memset(res,0, sizeof(res));
    for (int i=0;i<length;i++) 
        res[a[i]]++;
    for (int i=0;i<max_n;i++) {
        if (res[i]>0) {
            for (int j=1;j<=res[i];j++)
                cout<<i<<" ";
        }
    }
}
int main() {
    counting_sort();
    return 0;
}
