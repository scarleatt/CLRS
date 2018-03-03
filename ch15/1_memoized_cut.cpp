#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[11]={0,1,5,8,9,10,17,17,20,24,30};
vector<int> v;
int memorized_cut(int n) {
    if (v[n]>=0) return v[n];
    int q;
    if (n==0) {
        q=0;
    } else {
        q=INT_MIN;
        for (int i=1; i<=n; i++)
            q=max(q, p[i]+memorized_cut(n-i));
    }
    v[n]=q;
    return q;
}
int bottom_up_cut(int n) {
    v[0]=0;
    int q;
    for (int j=1; j<=n; j++) {
        q=INT_MIN;
        for (int i=1; i<=j; i++)
            q=max(q, p[i]+v[j-i]);
        v[j]=q;
    }
    return v[n];
}
int main() {
    int n=30;
    for (int i=0; i<=n; i++)
        v.push_back(INT_MIN);
    cout<<memorized_cut(n)<<endl;
    v.clear();
    cout<<bottom_up_cut(n)<<endl;
    return 0;
}
