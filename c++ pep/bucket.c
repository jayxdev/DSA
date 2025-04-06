#include <stdio.h>

#define BUCKETS 5

void bucketSort(int arr[], int n) {
    int i, j, k;
    int buckets[BUCKETS][n];
    int bucketCount[BUCKETS];

    for (i = 0; i < BUCKETS; i++) {
        bucketCount[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] / BUCKETS;
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    for (i = 0; i < BUCKETS; i++) {
        for (j = 0; j < bucketCount[i] - 1; j++) {
            for (k = 0; k < bucketCount[i] - j - 1; k++) {
                if (buckets[i][k] > buckets[i][k + 1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k + 1];
                    buckets[i][k + 1] = temp;
                }
            }
        }
    }

    k = 0;
    for (i = 0; i < BUCKETS; i++) {
        for (j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    int arr[100];

    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}