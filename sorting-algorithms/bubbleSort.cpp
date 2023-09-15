#include<iostream>
using namespace std;

// Algorithm implementation *Bubble Sort Optimized with swapped boolean*
int  bubbleSort(int arr[], int n){

  int i,j,temp, swapCounter; // temp to temporary store int value for swapping, swapCounter is for counting number of swaps.
  bool swapped;
  swapCounter = 0;

  for(i = 0; i < n - 1; i++ ){
    swapped = false;
    for (j = 0; j < n - 1; j++ ){
      if (arr[j] > arr[j + 1]){ // condition for potential swaps!
        temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
        swapped = true; // if this is true that means the array made a swap! else we can break out of the function
        swapCounter += 1; // increment for swapCounter 
      }
    }
    if (swapped == false)
        break;
  }
  return swapCounter;
}

// printArr helps print out the sorted array
void printArr(int arr[], int arrSize){

  int i;
  
  for (i = 0; i < arrSize; i++){
    cout << " " << arr[i];
  } 
}

int main(){
  int arr[] = {1, 5, 3, 25, 95, 12, 24, 66}; // intialize the array that has to be sorted
  int size = sizeof(arr) / sizeof(arr[0]); // getting the length of the array
  int totalSwaps = bubbleSort(arr, size); //Sorting the array
  cout << "Sorted Array (Bubble Sort): \n"; 
  printArr(arr, size); // Print the sorted array
  cout << "\nTotal number of swaps: \n" << totalSwaps; // Printing total number of swaps done by the algorithm.
  return 0;
}