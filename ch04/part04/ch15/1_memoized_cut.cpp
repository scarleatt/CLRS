#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[11]={0,1,5,8,9,10,17,17,20,24,30};
vector<int> v;
int cut(int n) {
    if (v[n]>=0) return v[n];
    int q;
    if (n==0) {
        q=0;
    } else {
        q=INT_MIN;
        for (int i=1; i<=n; i++)
            q=max(q, p[i]+cut(n-i));
    }
    v[n]=q;
    return q;
}
int main() {
    int n=40;
    for (int i=0; i<=n; i++)
        v.push_back(INT_MIN);
    cout<<cut(n)<<endl;
    return 0;
}
