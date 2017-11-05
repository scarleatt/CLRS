#include <iostream>
using namespace std;

int main() {
    int a[10] = {1,0,0,1,1};
    int b[10] = {1,1,1,1,1};
    int res[10];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < 5; i++) {
        int temp = a[i]+b[i]+res[i];
        if (temp >= 2) {
            res[i+1]++;
            res[i] = temp%2;
        } else {
            res[i] += temp;
        }
    }
    for (int j = 5; j >= 0; j--)
        cout<<res[j]<<"  ";
    cout<<endl;
    
    return 0;
}