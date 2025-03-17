#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mergesort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main() {
    int a[15000], n, i, j, ch, temp;
    clock_t start, end;

    while (1) {
        printf("\n1: For manual entry of N value and array elements");
        printf("\n2: To display time taken for sorting number of elements N in the range 500 to 14500");
        printf("\n3: To exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("\nEnter the number of elements: ");
            scanf("%d", &n);
            printf("\nEnter array elements: ");
            for (i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            start = clock();
            mergesort(a, 0, n - 1);
            end = clock();

            printf("\nSorted array is: ");
            for (i = 0; i < n; i++) {
                printf("%d\t", a[i]);
            }
            printf("\nTime taken to sort %d numbers using Merge Sort is %f Secs", n, ((double)(end - start)) / CLOCKS_PER_SEC);
            break;

        case 2:
            n = 500;
            while (n <= 14500) {
                for (i = 0; i < n; i++) {
                    a[i] = n - i;  // Example: descending order. Replace with random numbers if needed.
                }
                printf("\nSorting %d numbers\n", n);

                // Merge Sort
                start = clock();
                mergesort(a, 0, n - 1);
                end = clock();
                printf("Time taken for Merge Sort: %f Secs\n", ((double)(end - start)) / CLOCKS_PER_SEC);

                n = n + 1000;
            }
            break;

        case 3:
            exit(0);
        }
    }

    return 0;
}

void mergesort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the two halves
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);

        // Merge the sorted halves
        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the values
    int leftArray[n1], rightArray[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = a[mid + 1 + j];
    }

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            a[k] = leftArray[i];
            i++;
        } else {
            a[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements, if any
    while (i < n1) {
        a[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = rightArray[j];
        j++;
        k++;
    }
}
