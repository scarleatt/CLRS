#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN=7;
vector<int> p={30,35,15,5,10,20,25};
const int n=MAXN-1;
int m[n+1][n+1],s[n+1][n+1];

void matrix_chain_order() {
    for (int i=0; i<=n; i++) m[i][i]=0;
    for (int l=2; l<=n; l++)
        for (int i=1; i<=n-l+1; i++) {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for (int k=i; k<=j-1; k++) {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if (q<m[i][j]) {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
}
void print_optimal_parens(int i, int j) {
    if (i==j) {
        cout<<"A"<<i;
    } else {
        cout<<"(";
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j]+1, j);
        cout<<")";
    }
}

int main() {
    matrix_chain_order();
    print_optimal_parens(1,6);
    return 0;
}
