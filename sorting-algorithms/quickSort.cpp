// Big thanks! Implemented by following this video https://www.youtube.com/watch?v=0jDiBM68NGU
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

//Function declarations
void swap(int *x, int *y);
void quickSort(int arr[], int length);
void quickSortRecursion(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArr(int arr[], int arrSize);


// Function to swap two integers using pointers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform Quick Sort on an array
void quickSort(int arr[], int length) {
    srand(time(NULL));
    quickSortRecursion(arr, 0, length - 1);
}

// Recursive function for Quick Sort
void quickSortRecursion(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quickSortRecursion(arr, low, pivot_index - 1);
        quickSortRecursion(arr, pivot_index + 1, high);
    }
}

// Function to partition the array and place the pivot element in its correct position
int partition(int arr[], int low, int high) {
    int pivot_index = low + (rand() % (high - low + 1));
    if (pivot_index != high) {
        swap(&arr[pivot_index], &arr[high]);
    }
    int pivot_value = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot_value) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);

    return i;
}

// Function to print the elements of an array
void printArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " "; // Output each element followed by a space
    }
    cout << endl; // Print a newline after the array.
}

int main() {
    int arr[] = {1, 5, 3, 25, 95, 12, 24, 66};
    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Quick Sort:" << endl;
    printArr(arr, length);

    quickSort(arr, length);

    cout << "\nAfter Quick Sort:" << endl;
    printArr(arr, length);

    return 0;
}
