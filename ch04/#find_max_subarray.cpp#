#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
//暴力求解法求解最小子数组
int find_max_array(vector<int> v) {
    int max = INT_MIN, sum;
    for (int i = 0; i < v.size(); i++) {
        sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            if (sum > max)
                max = sum;
        }
    }
    return max;
}
int find_max_crossing_subarray(vector<int> a, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid+1; j <= high; j++) {
        sum += a[j];
        if (sum > right_sum)
            right_sum = sum;
    }
    return left_sum+right_sum;
}
int find_maximum_subarray(vector<int> a, int low, int high) {
    if (high == low)
        return a[low];
    else {
        int left_sum, right_sum, cross_sum, mid = (low+high)/2;
        left_sum = find_maximum_subarray(a, low, mid);
        right_sum = find_maximum_subarray(a, mid+1, high);
        cross_sum = find_max_crossing_subarray(a, low, mid, high);
        if (left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}

int main() {
    vector<int> a = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    print find_max_array(a);
    print find_maximum_subarray(a, 0, a.size()-1);
    return 0;
}