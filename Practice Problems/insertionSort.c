#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int insertion_sort(int arr[], int size);
int read_file(const char *filename, int arr[], int *size);
void write_file(const char *filename, int arr[], int size);
int is_best_case(int arr[], int size);
int is_worst_case(int arr[], int size);

void display_menu();
void handle_sorting(const char *input_file, const char *output_file);

int main() {
    int choice;
    char *input_file = "a.txt";
    char *output_file = "out.txt";

    while (1) {
        display_menu();
        printf("Enter your choice \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handle_sorting(input_file, output_file);
                break;
            case 2:
                handle_sorting(input_file, output_file);
                break;
            case 3:
                handle_sorting(input_file, output_file);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\nMAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
}

void handle_sorting(const char *input_file, const char *output_file) {
    int data[500];
    int size = 0;
    int comparisons = 0;

    if (read_file(input_file, data, &size) == -1) {
        printf("Error reading file: %s\n", input_file);
        return;
    }

    printf("Before Sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    comparisons = insertion_sort(data, size);

    write_file(output_file, data, size);

    printf("After Sorting: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Number of Comparisons: %d\n", comparisons);

    if (is_best_case(data, size)) {
        printf("Best case\n");
    } else if (is_worst_case(data, size)) {
        printf("Worst case\n");
    } else {
        printf("Average case\n");
    }
}

int insertion_sort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = key;

        if (j >= 0) {
            comparisons++;
        }
    }
    return comparisons;
}

int read_file(const char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }
    *size = 0;
    while (fscanf(file, "%d", &arr[*size]) != EOF) {
        (*size)++;
    }
    fclose(file);
    return 0;
}

void write_file(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int is_best_case(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int is_worst_case(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}
