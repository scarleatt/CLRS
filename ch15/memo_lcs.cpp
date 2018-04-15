#include <iostream>
using namespace std;
string x="ABCBDAB";
string y="BDCABA";
const int m=7;
const int n=6;
int c[m+1][n+1];
int lcs() {
    for (int i=0;i<=m;i++)
        c[i][0]=0;
    for (int j=0;j<=n;j++)
        c[0][j]=0;
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
int memo_lcs(int i,int j) {
    if (c[i][j]!=0||i==0||j==0)
        return c[i][j];
    if (x[i-1]==y[j-1]) {
        c[i][j]=memo_lcs(i-1,j-1)+1;
    } else {
        c[i][j]=max(memo_lcs(i,j-1),memo_lcs(i-1,j));
    }
    return c[i][j];
}
void print_lcs() {
    int i=m,j=n,r=c[m][n];
    char s[n+1];
    while (i>0&&j>0) {
        if (x[i-1]==y[j-1]) {
            cout<<x[i-1];
            s[r]=x[i-1];
            r--;
            i--; j--;
        } else if (c[i-1][j]>=c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
}
int main() {
    cout<<memo_lcs(m,n)<<endl;
    print_lcs();
    return 0;
}
