#include <iostream>
using namespace std;

int search(int arr[], int l, int r, int x) {
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (arr[m] == x) return m;
    if (arr[m] > x) return search(arr, l, m - 1, x);
    return search(arr, m + 1, r, x);
}

int main() {
    int arr[] = {2,5,8,12,16,23,38,56,72,91};
    cout << search(arr, 0, 9, 23);
    return 0;
}
