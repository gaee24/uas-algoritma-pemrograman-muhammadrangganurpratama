#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan Linear Search
int linearSearch(vector<int> arr, int x) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 9, 1, 8, 5, 7};
    int x = 1;
    int n = arr.size();

    // Fungsi panggilan untuk Linear Search
    int result = linearSearch(arr, x);
    (result == -1) ? 
    cout << "Element is not present in array":
    cout << "Element is present at index " << result;
    return 0;
}
