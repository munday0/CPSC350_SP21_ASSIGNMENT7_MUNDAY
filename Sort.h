/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 7
*/

//Header file for Sort

#include <iostream>

//sort ints
void bubbleSort(double* arr, int n){
  for(int i = 0; i < n-1; ++i){
    for(int j = 0; j < n-i-1; ++j){
      if(arr[j] > arr[j+1]){ //number of comps
        double temp = arr[j];
        arr[j] = arr[j+1]; //number of swaps
        arr[j+1] = temp;
      }
    }
  }
}

//selection sort - pick min each time and put in position at front of the array
void selectionSort(double* arr, int n){
  int currMinIdx;
  for(int j = 0; j < n-1; ++j){
    currMinIdx = j;
    for(int k = j+1; k < n; ++k){
      if(arr[k]< arr[currMinIdx]){ //swap
        currMinIdx = k;
      }
    }
    double temp = arr[j];
    arr[j] = arr[currMinIdx];
    arr[currMinIdx] = temp;
  }
}

//insertion sort
void insertionSort(double* arr, int n){
  for(int j = 1; j < n; ++j){
    double temp = arr[j];
    int k = j;
    while(k >0 && arr[k-1] >= temp){
      arr[k] = arr[k-1];
      --k;
    }
    arr[k] = temp;
  }
}

//merge
void merge(double* arr, int lo, int hi);

//merge sort
void mergeSort(double* arr, int lo, int hi){
  if(lo < hi){
    int middle = (lo+hi)/2;
    mergeSort(arr,lo,middle);
    mergeSort(arr,middle+1,hi);
    merge(arr,lo,hi);
  }
}

//merge implementation
void merge(double* arr, int lo, int hi){
  double* newArr = new double[hi-lo+1];
  int middle  = (hi + lo)/2;
  int k = 0;
  int i;
  int j;
  for(i = lo; i <=middle; ++i){
    newArr[k++] = arr[i];
  }
  for(j = hi; j >= middle+1; --j){
    newArr[k++] = arr[j];
  }
  i = 0;
  k = lo;
  j = (hi-lo); //number of elements -1
  while(i <= j){
    if(newArr[i]< newArr[j]){
      arr[k++] = newArr[i++];
    } else{
      arr[k++] = newArr[j--];
    }
  }
}

//partition for quicksort
double partition(double* arr, int lo, int hi){
  double pivot = arr[hi]; //this is dangerous if data is sorted
  int smallValue = lo-1;
  for(int j = lo; j <= hi-1; ++j){
    if(arr[j] < pivot){
      ++smallValue;
      double temp = arr[j];
      arr[j] = arr[smallValue];
      arr[smallValue] = temp;
    }
  }
  double pt = arr[smallValue+1]; //put pivot into place
  arr[smallValue+1] = arr[hi];
  arr[hi] = pt;
  return (smallValue+1);
}

//quicksort
void quickSort(double* arr, int lo, int hi){
  if(lo < hi){
    int partitionIdx = partition(arr,lo,hi);
    quickSort(arr,lo,partitionIdx-1);
    quickSort(arr,partitionIdx+1,hi);
  }
}

//shell sort
void shellSort(double* arr, int arrSize){
  for (int gap = arrSize/2; gap > 0; gap /= 2) { //gap vals
    for (int i = gap; i < arrSize; i++) {
      double temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}
