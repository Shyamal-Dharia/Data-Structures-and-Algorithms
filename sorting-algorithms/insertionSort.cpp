#include<iostream>
using namespace std;


// Algorithm implementation *Insertion Sort*
void insertionSort(int arr[], int arrSize){

  int i, j, currentVar; // currentVar to store the value that needs to be inserted

  for (i = 1; i < arrSize; i++){
    currentVar = arr[i];
    j = i - 1;
    // swifting elements to right until correct position is found
    while(j >= 0 && arr[j]>currentVar){
      arr[j + 1] = arr[j];
      j --;
    }
    arr[j + 1] = currentVar; // place the currentVar in its correct position
  }

}


// printArr helps print out the sorted array
void printArr(int arr[], int arrSize) {

  int i;

  for (i = 0; i < arrSize; i++) {
    cout << " " << arr[i];
  }
  
}

int main(){
  int arr[] = {1, 5, 3, 25, 95, 12, 24, 66}; // intialize the array that has to be sorted
  int sizeArr = sizeof(arr) / sizeof(arr[0]); // getting the length of the array
  insertionSort(arr,sizeArr); //Sorting the array
  cout << "Sorted Array (Insertion Sort)";
  printArr(arr,sizeArr); // Print the sorted array
}

