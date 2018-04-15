#include <iostream>
using namespace std;
string x="ABCBDAB";
string y="BDCABA";
const int m=7;
const int n=6;
int c[m+1][n+1];
int lcs() {
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (x[i-1]==y[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
            } else {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    return c[m][n];
}

void print_lcs() {
    int r=c[m][n];
    char s[100];
    int i=m,j=n;
    while (i>0 && j>0) {
        if (x[i-1]==y[j-1]) {
            s[r]=x[i-1];
            r--;
            i--;
            j--;
        } else if (c[i-1][j]>=c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    for (i=1;i<n;i++)
        cout<<s[i];
}
int main() {
    cout<<lcs()<<endl;
    print_lcs();
    return 0;
}
