#include <iostream>
using namespace std;

// Implementation of Selection Sort algorithm which selects the maximum number and swaps it
// Selection Sort is more efficient than Bubble Sort in terms of the number of swaps.
int selectionSort(int arr[], int sizeArr) {
  int i, j, maxIdx, temp, swapCounter;
  swapCounter = 0;

  for (i = sizeArr - 1; i > 0; i--) { // Loop in reverse, starting with the last element
    maxIdx = i;

    for (j = i - 1; j >= 0; j--) { // Inner loop also in reverse, looking for the maximum value
      if (arr[j] > arr[maxIdx]) { // Condition to find the maximum value index for swapping
        maxIdx = j;
      }
    }

    if (maxIdx != i) { // Actual swapping
      temp = arr[maxIdx];
      arr[maxIdx] = arr[i];
      arr[i] = temp;
      swapCounter += 1;
    }
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
  int arrSize = sizeof(arr) / sizeof(arr[0]); // Get the length of the array
  int totalSwaps = selectionSort(arr, arrSize); // Sort the array using Selection Sort
  cout << "Sorted Array (Selection Sort): \n";
  printArr(arr, arrSize); // Print the sorted array
  cout << "\nTotal number of swaps: \n" << totalSwaps; // Print the total number of swaps performed by the algorithm.
  return 0;
}
