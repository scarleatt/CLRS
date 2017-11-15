def find_maximum_array(a):
    l = len(a)
    max_sum = 0
    for i in range(l):
        sum = 0
        for j in range(i,l):
            sum += a[j]
            if sum > max_sum:
                max_sum = sum
    return max_sum

def find_max_cross_subarray(a, low, mid, high):
    left_sum = 0
    sum = 0
    for i in range(mid, low, -1):
        sum+=a[i]
        if sum>left_sum:
            left_sum=sum
    sum = 0
    right_sum = 0
    for i in range(mid+1,high):
        sum+=a[i]
        if sum>right_sum:
            right_sum=sum
    return left_sum+right_sum

def recur_find_maximum_array(a, low, high):
    if low==high:
        return a[low]
    else:
        mid = (low+high)/2
        left_sum = recur_find_maximum_array(a, low, mid)
        right_sum = recur_find_maximum_array(a, mid+1, high)
        cross_sum = find_max_cross_subarray(a, low, mid, high)
        if left_sum>right_sum & left_sum>cross_sum:
            return left_sum
        elif right_sum>left_sum & right_sum>cross_sum:
            return right_sum
        else:
            return cross_sum

from time import time
a = []
recur_t = []
no_recur_t = []
for i in range(120):
    a.append(i)
    t1 = time()
    recur_find_maximum_array(a, 0, len(a)-1)
    t2 = time()
    find_maximum_array(a)
    t3 = time()
    recur_t.append((t2-t1)*1000000)
    no_recur_t.append((t3-t2)*1000000)

import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot(111)
ax.scatter(a, recur_t, c='red', marker='s')
ax.scatter(a, no_recur_t)
plt.show()

# a = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
# print recur_find_maximum_array(a, 0, len(a)-1)