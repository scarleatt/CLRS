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
int a[20]={90,100,16,4,19,14,74,9,32,23,88,18};
int length=12;
void bucker_sort(int a[]) {
    int min_n=INT_MAX;
    int max_n=INT_MIN;
    for (int i=0; i<length;i++) {
        if (a[i]>max_n) max_n=a[i];
        if (a[i]<min_n) min_n=a[i];
    }
    map<int,multiset<int>>m;
    multiset<int> s;
    int x;
    for (int i=0; i<length; i++) {
        x=a[i]/10;
        s.insert(a[i]);
        if (m.find(x)==m.end()) {
            m.insert(make_pair(x,s));
        } else {
            m[x].insert(a[i]);
        }
        s.clear();
    }
    int index=0;
    map<int,multiset<int>>::iterator it;
    multiset<int>::iterator sit;
    for (it=m.begin(); it!=m.end(); it++) {
        s=(*it).second;
        for (sit=s.begin();sit!=s.end();sit++,index++) {
            a[index]=(*sit);
        }
    }
    for (int i=0; i<length; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main() {
    bucker_sort(a);
    return 0;
}
