#include <stdio.h>
#include <limits.h>

void findSecondSmallest(int arr[], int n) {
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    printf("Second smallest element: %d\n", secondSmallest);
}

int main() {
    int arr[] = {7, 1, 5, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    findSecondSmallest(arr, n);
    return 0;
}