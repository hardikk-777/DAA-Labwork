#include <iostream>
using namespace std;

int max3(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    if (b >= a && b >= c) return b;
    return c;
}

int maxCross(int a[], int l, int m, int r) {
    int sum = 0;
    int leftMax = a[m];
    for (int i = m; i >= l; i--) {
        sum += a[i];
        if (sum > leftMax)
            leftMax = sum;
    }

    sum = 0;
    int rightMax = a[m + 1];
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        if (sum > rightMax)
            rightMax = sum;
    }

    return leftMax + rightMax;
}

int maxSub(int a[], int l, int r) {
    if (l == r) return a[l];

    int m = (l + r) / 2;

    int left = maxSub(a, l, m);
    int right = maxSub(a, m + 1, r);
    int cross = maxCross(a, l, m, r);

    return max3(left, right, cross);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    cout << maxSub(arr, 0, n - 1);
    return 0;
}
