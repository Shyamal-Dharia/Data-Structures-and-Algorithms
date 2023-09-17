#include<iostream>
using namespace std;

// Implementation of the Insertion Sort algorithm
void insertionSort(int arr[], int arrSize) {

  int i, j, currentVar; // currentVar is used to store the value that needs to be inserted

  for (i = 1; i < arrSize; i++) {
    currentVar = arr[i];
    j = i - 1;
    
    // Shifting elements to the right until the correct position for currentVar is found
    while (j >= 0 && arr[j] > currentVar) {
      arr[j + 1] = arr[j];
      j--;
    }
    
    arr[j + 1] = currentVar; // Place the currentVar in its correct position
  }

}

// Helper function to print out the sorted array
void printArr(int arr[], int arrSize) {

  for (int i = 0; i < arrSize; i++) {
    cout << " " << arr[i];
  }
  
}

int main() {
  int arr[] = {1, 5, 3, 25, 95, 12, 24, 66}; // Initialize the array to be sorted
  int sizeArr = sizeof(arr) / sizeof(arr[0]); // Get the length of the array
  insertionSort(arr, sizeArr); // Sort the array using Insertion Sort
  cout << "Sorted Array (Insertion Sort):";
  printArr(arr, sizeArr); // Print the sorted array
  return 0;
}
