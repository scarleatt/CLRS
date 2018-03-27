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
void radix_sort(int a[],int d) {
    map<int,vector<int>>m;
    vector<int> v;
    int x;
    for (int i=0; i<length; i++) {
        if (d==1)
            x=a[i]%(d*10);
        else
            x=a[i]/((d-1)*10);
        v.push_back(a[i]);
        if (m.find(x)==m.end()) {
            m.insert(make_pair(x,v));
        } else {
            m[x].push_back(a[i]);
        }
        v.clear();
    }
    int index=0;
    map<int,vector<int>>::iterator it;
    for (it=m.begin(); it!=m.end(); it++) {
        v=(*it).second;
        for (int i=0;i<v.size(); i++,index++) {
            a[index]=v[i];
        }
    }
    for (int i=0; i<length; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main() {
    int max_n=max(a[0],a[length]);
    int max_cnt=0;
    while (max_n>0) {
        max_n/=10; max_cnt++;
    }
    for (int i=1;i<=max_cnt;i++)
        radix_sort(a,i);
    return 0;
}
