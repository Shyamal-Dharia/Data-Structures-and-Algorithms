#include <iostream>
using namespace std;

// Algorithm implementation *Selection Sort with selecting Maximum number and swapping it*
// This algorithm is better than bubble sort as it perfroms smaller number of swaps compared to bubble sort.
int selectionSort(int arr[], int sizeArr) {

  int i, j, maxIdx, temp, swapCounter;
  swapCounter = 0;

  for (i = sizeArr - 1; i > 0; i--) { // looping in reverse, i = the last int value of our array
    
    maxIdx = i;
    
    for (j = i - 1; j >= 0; j--) { // inner loops is also in reverse, j = last second int value of our array
      if (arr[j] > arr[maxIdx]) { // condition for finding maximum value index so that we can swap the values with index [i]!
        maxIdx = j;
      }
    }

    if (maxIdx != i) { // Actual swaps!
      temp = arr[maxIdx];
      arr[maxIdx] = arr[i];
      arr[i] = temp;
      swapCounter += 1;
    }
  }

  return swapCounter;
}

// printArr helps print out the sorted array
void printArr(int arr[], int arrSize) {

  int i;

  for (i = 0; i < arrSize; i++) {
    cout << " " << arr[i];
  }
}

int main() {
  int arr[] = {1, 5, 3, 25, 95, 12, 24, 66}; // intialize the array that has to be sorted
  int arrSize = sizeof(arr) / sizeof(arr[0]); // getting the length of the array
  int totalSwaps = selectionSort(arr, arrSize); //Sorting the array
  cout << "Sorted Array (Selection Sort): \n";
  printArr(arr, arrSize); // Print the sorted array
  cout << "\nTotal number of swaps: \n" << totalSwaps; // Printing total number of swaps done by the algorithm.
  return 0;
}
