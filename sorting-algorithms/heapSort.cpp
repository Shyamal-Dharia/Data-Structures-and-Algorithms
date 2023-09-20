#include<iostream>
using namespace std;

// Function to swap two integers using pointers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to print the elements of an array
void printArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " "; // Output each element followed by a space
    }
    cout << endl; // Print a newline after the array.
}

// Function to heapify a subtree rooted at node i
void heapify(int arr[], int arrSize, int i) {
    // Initialize the largest as the root
    int largest = i;
 
    // Calculate the indices of the left and right children
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
 
    // If the left child is larger than the root
    if (leftChild < arrSize && arr[leftChild] > arr[largest])
        largest = leftChild;
 
    // If the right child is larger than the largest so far
    if (rightChild < arrSize && arr[rightChild] > arr[largest])
        largest = rightChild;
 
    // If the largest is not the root
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Swap the root with the largest element
 
        // Recursively heapify the affected sub-tree
        heapify(arr, arrSize, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int arrSize) {
    // Build a max-heap from the input array
    for (int i = arrSize / 2 - 1; i >= 0; i--) {
        heapify(arr, arrSize, i);
    }

    // Extract elements from the heap one by one
    for (int i = arrSize - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Swap the maximum element with the last element
        heapify(arr, i, 0); // Heapify the reduced heap
    }
}

int main() {
    int arr[] = {1, 5, 3, 25, 95, 12, 24, 66};
    int length = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, length);

    cout << "Sorted Array (Heap Sort):" << endl;
    printArr(arr, length);

    return 0;
}
