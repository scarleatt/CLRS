#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int p[11]={0,1,5,8,9,10,17,17,20,24,30};
int s[100];
vector<int> v;
const int n=30, c=1;
int memorized_cut(int n) {
    if (v[n]>=0) return v[n];
    int q;
    if (n==0) {
        q=0;
    } else {
        q=INT_MIN;
        for (int i=1; i<=n; i++) {
            if (q<p[i]+memorized_cut(n-i)) {
                q=p[i]+memorized_cut(n-i);
                s[n]=i;
            }
        }
    }
    v[n]=q;
    return q;
}
int bottom_up_cut(int n) {
    v[0]=0;
    int q;
    for (int j=1; j<=n; j++) {
        q=INT_MIN;
        for (int i=1; i<=j; i++) {
            if (q<p[i]+v[j-i]) {
                q=p[i]+v[j-i];
                s[j]=i;
            }
        }
        v[j]=q;
    }
    return v[n];
}
int main() {
    int count,res;

    cout<<"memorized_cut: "<<endl;
    for (int i=0; i<=n; i++)
        v.push_back(INT_MIN);
    memset(s, 0, sizeof(s));
    count=0;
    res=bottom_up_cut(n);
    for (int i=1; i<=n; i++) {
        cout<<s[i]<<" "; count++;
    }
    cout<<endl;
    cout<<res-count*c;
    cout<<endl;
    v.clear();

    cout<<"bottom_up_cut: "<<endl;
    memset(s, 0, sizeof(s));
    count=0;
    res=bottom_up_cut(n);
    for (int i=1; i<=n; i++) {
        cout<<s[i]<<" "; count++;
    }
    cout<<endl;
    cout<<res-count*c;
    cout<<endl;
    return 0;
}
