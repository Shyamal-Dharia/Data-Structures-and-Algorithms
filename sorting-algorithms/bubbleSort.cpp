#include<iostream>
using namespace std;

// Implementation of Bubble Sort algorithm optimized with a swapped boolean
// Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
// The optimization with the 'swapped' boolean checks if any swaps were made during a pass, and if not, the algorithm terminates early.
int bubbleSort(int arr[], int n) {
  int i, j, temp, swapCounter; // 'temp' temporarily stores an integer value during swapping, 'swapCounter' counts the number of swaps made.
  bool swapped;
  swapCounter = 0;

  for(i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - 1; j++) {
      if (arr[j] > arr[j + 1]) { // Condition for potential swaps
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        swapped = true; // If this is true, it means the array made a swap; otherwise, we can break out of the loop
        swapCounter += 1; // Increment the swapCounter
      }
    }
    if (!swapped) // If no swaps were made during a pass, the array is already sorted, so we break out of the loop
      break;
  }
  return swapCounter;
}

// Helper function to print out the elements of the sorted array
void printArr(int arr[], int arrSize) {
  for (int i = 0; i < arrSize; i++) {
    cout << " " << arr[i];
  }
}

int main() {
  int arr[] = {1, 5, 3, 25, 95, 12, 24, 66}; // Initialize the array to be sorted
  int size = sizeof(arr) / sizeof(arr[0]); // Get the length of the array
  int totalSwaps = bubbleSort(arr, size); // Sort the array using Bubble Sort
  cout << "Sorted Array (Bubble Sort): \n"; 
  printArr(arr, size); // Print the sorted array
  cout << "\nTotal number of swaps: \n" << totalSwaps; // Print the total number of swaps made by the algorithm.
  return 0;
}
