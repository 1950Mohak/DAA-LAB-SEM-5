#include <stdio.h>

int bS(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] < target) {
            start = mid + 1;
        } else if (arr[mid] > target) {
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    
    int n, target;
    printf("Enter size of array \n");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target \n");
    scanf("%d", &target);

    int ans = bS(arr, n, target);

    if (ans != -1) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}


