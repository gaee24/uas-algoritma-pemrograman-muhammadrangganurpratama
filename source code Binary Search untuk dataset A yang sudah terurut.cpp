#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan Binary Search
int binarySearch(vector<int> arr, int x) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika elemen tengah sama dengan nilai yang dicari
        if (arr[mid] == x)
            return mid;

        // Jika nilai yang dicari lebih kecil dari elemen tengah
        if (arr[mid] < x)
            left = mid + 1;

        // Jika nilai yang dicari lebih besar dari elemen tengah
        else
            right = mid - 1;
    }

    // Jika nilai tidak ditemukan
    return -1;
}

int main() {
    vector<int> arr = {4, 7, 9, 10, 20};
    int x = 10;
    int n = arr.size();

    // Fungsi panggilan untuk Binary Search
    int result = binarySearch(arr, x);
    (result == -1) ? 
cout << "Element is not present in array":
cout << "Element is present at index " << result;
    return 0;
}
