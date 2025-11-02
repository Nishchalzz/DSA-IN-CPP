#include<iostream>
#include<vector>
using namespace std;

long long merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++) left[i] = arr[l + i];
    for(int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    long long invCount = 0;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (n1 - i); // Remaining elements in left[] are inversions
        }
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];

    return invCount;
}

long long mergesort(int arr[], int l, int r) {
    long long count = 0;
    if(l < r) {
        int m = l + (r - l) / 2;
        count += mergesort(arr, l, m);
        count += mergesort(arr, m + 1, r);
        count += merge(arr, l, m, r);
    }
    return count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;
    cout << mergesort(arr, 0, n - 1) << endl; // Output: 3
    return 0;
}
