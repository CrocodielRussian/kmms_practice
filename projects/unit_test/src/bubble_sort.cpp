#include "bubble_sort.hpp"

void BubbleSort::sort(std::vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}
