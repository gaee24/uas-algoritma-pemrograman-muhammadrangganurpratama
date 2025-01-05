#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Order {
    int orderID;
    std::string pickupLocation;
    std::string destinationLocation;
    std::string deliveryTime; // Format: "YYYY-MM-DD HH:MM:SS"
};

// fungsi untuk menggabungkan dua subarray
void merge(std::vector<Order>& orders, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Order> leftArray(n1);
    std::vector<Order> rightArray(n2);

    for (int i = 0; i < n1; ++i)
        leftArray[i] = orders[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = orders[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i].deliveryTime <= rightArray[j].deliveryTime) {
            orders[k++] = leftArray[i++];
        } else {
            orders[k++] = rightArray[j++];
        }
    }

    while (i < n1) {
        orders[k++] = leftArray[i++];
    }

    while (j < n2) {
        orders[k++] = rightArray[j++];
    }
}

// fungsi untuk mengimplementasikan Merge Sort
void mergeSort(std::vector<Order>& orders, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(orders, left, mid);
        mergeSort(orders, mid + 1, right);
        merge(orders, left, mid, right);
    }
}

// fungsi untuk print order
void printOrders(const std::vector<Order>& orders) {
    for (const auto& order : orders) {
        std::cout << "ID orderan: " << order.orderID
                  << ", Titik Penjemputan: " << order.pickupLocation
                  << ", Lokasi tujuan: " << order.destinationLocation
                  << ", Waktu pengantaran: " << order.deliveryTime << std::endl;
    }
}

int main() {
    std::vector<Order> orders = {
        {1, "Lokasi A", "Lokasi B", "2025-01-05 10:00:00"},
        {2, "Lokasi C", "Lokasi D", "2024-12-25 09:00:00"},
        {3, "Lokasi E", "Lokasi F", "2025-01-01 15:30:00"},
        {4, "Lokasi G", "Lokasi H", "2025-01-03 12:00:00"}
    };

    std::cout << "Pesanan sebelum di Sorting:\n";
    printOrders(orders);

    mergeSort(orders, 0, orders.size() - 1);

    std::cout << "\nPesanan setelah diurutkan berdasarkan waktu pengiriman:\n";
    printOrders(orders);

    return 0;
}
