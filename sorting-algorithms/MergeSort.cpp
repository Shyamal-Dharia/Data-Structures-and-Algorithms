#include<iostream>
using namespace std;

// Function declarations
void merge(int arr[], int start, int mid, int end, int length);
void mergeSort(int arr[], int start, int end, int length);

// Merge function to combine two sorted subarrays into one
void merge(int arr[], int start, int mid, int end, int length) {
    int leftSubArr = start;        // Index for the left subarray
    int rightSubArr = mid + 1;     // Index for the right subarray
    int tempArrIdx = start;        // Index for the temporary array

    int* temp = new int[length];   // Temporary array with dynamic allocation

    // Compare and place the smaller values into the temporary array
    while (leftSubArr <= mid && rightSubArr <= end) {
        if (arr[leftSubArr] <= arr[rightSubArr]) {
            temp[tempArrIdx] = arr[leftSubArr]; // Element from the left subarray is smaller
            leftSubArr++;
        }
        else {
            temp[tempArrIdx] = arr[rightSubArr]; // Element from the right subarray is smaller
            rightSubArr++;
        }
        tempArrIdx++;
    }

    // Copy the remaining elements from the left subarray to the temporary array
    while (leftSubArr <= mid) {
        temp[tempArrIdx] = arr[leftSubArr];
        leftSubArr++;
        tempArrIdx++;
    }

    // Copy the remaining elements from the right subarray to the temporary array
    while (rightSubArr <= end) {
        temp[tempArrIdx] = arr[rightSubArr];
        rightSubArr++;
        tempArrIdx++;
    }

    // Update the original array with the sorted values from the temporary array
    for (int s = start; s <= end; s++) {
        arr[s] = temp[s];
    }

    // Delete the dynamically allocated temporary array to avoid memory leaks
    delete[] temp;
}

// Merge Sort function to recursively divide and merge the array
void mergeSort(int arr[], int start, int end, int length) {
    if (start < end) {
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid, length);      // Recursively sort the left subarray
        mergeSort(arr, mid + 1, end, length);    // Recursively sort the right subarray
        merge(arr, start, mid, end, length);     // Merge the two sorted subarrays
    }
}

// Function to print the elements of an array
void printArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " "; // Output each element followed by a space
    }
    cout << endl; // Add this to print a newline after the array.
}

int main() {
    int arr[] = {1, 5, 3, 25, 95, 12, 24, 66};
    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Merge Sort:" << endl;
    printArr(arr, length);

    mergeSort(arr, 0, length - 1, length);

    cout << "\nAfter Merge Sort:" << endl;
    printArr(arr, length);

    return 0;
}
