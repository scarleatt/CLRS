#include <iostream>
using namespace std;
int p[10]={30,35,15,5,10,20,25};
int m[100][100];
int n=6;
int recur_chain(int i, int j) {
    if (m[i][j]<INT_MAX) return m[i][j];
    if (i==j) {
        m[i][j]=0;
    } else {
        for (int k=i;k<j;k++) {
            int q=recur_chain(i,k)+recur_chain(k+1,j)+p[i-1]*p[k]*p[j];
            if (q<m[i][j]) {
                m[i][j]=q;
            }
        }
    }
    return m[i][j];
}
int main() {
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            m[i][j]=INT_MAX;
        }
    }
    cout<<recur_chain(1,n);
    return 0;
}
