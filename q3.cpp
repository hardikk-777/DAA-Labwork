#include <iostream>
using namespace std;

int part(int a[], int l, int h) {
    int p = a[h], i = l - 1;
    for (int j = l; j < h; j++)
        if (a[j] <= p) swap(a[++i], a[j]);
    swap(a[i+1], a[h]);
    return i + 1;
}

void sort(int a[], int l, int h) {
    if (l < h) {
        int p = part(a, l, h);
        sort(a, l, p - 1);
        sort(a, p + 1, h);
    }
}

int main() {
    int arr[] = {4,2,6,9,2};
    sort(arr, 0, 4);
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
    return 0;
}
