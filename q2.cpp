#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
     L[i] = a[l+i];
    for (int i = 0; i < n2; i++) 
    R[i] = a[m+1+i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] < R[j]) ? L[i++] : R[j++];
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void sort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    sort(a, l, m);
    sort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int arr1[] = {12,11,13,5,6,7};
    int arr2[] = {38,27,43,3,9,82,10};

    sort(arr1, 0, 5);
    sort(arr2, 0, 6);

    for (int i = 0; i < 6; i++) cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < 7; i++) cout << arr2[i] << " ";

    return 0;
}
