/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 7
*/

//Main

#include "Sort.h"
#include "Rng.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char const *argv[]) {
  Rng rng;
  string fileName = "";
  int numDoubles;
  cout << argv[1] << endl;
  if (argv[1] == "create"s) { //the s here allows for comparison as string
    cout << "Enter file name: " << endl;
    cin >> fileName;

    cout << "Enter number of doubles to create: " << endl;
    cin >> numDoubles;

    rng.writeRandNums(numDoubles, fileName);
  }
  else if(argv[1] == "sort"s){ //the s here allows for comparison as string
    cout << "Enter file name: " << endl;
    cin >> fileName;

    //for accessing time
    time_t start, end;

    //need 6 copies of array to sort with 6 different sorting algorithms
    //Quicksort
    cout << "Quicksort" << endl;

    //get/print current time
    time(&start);
    cout << "Time started: " << ctime(&start);

    double *arr_QuickSort = rng.readRandNums(fileName);
    quickSort(arr_QuickSort,0,rng.arrSize);

    //get/print current time
    time(&end);
    cout << "Time ended: " << ctime(&end) << endl;

    ////////////////////////////////////////////////////////

    //Merge sort
    cout << "Merge sort" << endl;

    //get/print current time
    time(&start);
    cout << "Time started: " << ctime(&start);

    double *arr_MergeSort = rng.readRandNums(fileName);
    mergeSort(arr_MergeSort,0,rng.arrSize);

    //get/print current time
    time(&end);
    cout << "Time ended: " << ctime(&end) << endl;

    ////////////////////////////////////////////////////////

    //Selection sort
    cout << "Selection sort" << endl;

    //get/print current time
    time(&start);
    cout << "Time started: " << ctime(&start);

    double *arr_SelectionSort = rng.readRandNums(fileName);
    selectionSort(arr_SelectionSort,rng.arrSize);

    //get/print current time
    time(&end);
    cout << "Time ended: " << ctime(&end) << endl;

    ////////////////////////////////////////////////////////

    //Insertion sort
    cout << "Insertion sort" << endl;

    //get/print current time
    time(&start);
    cout << "Time started: " << ctime(&start);

    double *arr_InsertionSort = rng.readRandNums(fileName);
    insertionSort(arr_InsertionSort,rng.arrSize);

    //get/print current time
    time(&end);
    cout << "Time ended: " << ctime(&end) << endl;

    ////////////////////////////////////////////////////////

    //Bubble sort
    cout << "Bubble sort" << endl;

    //get/print current time
    time(&start);
    cout << "Time started: " << ctime(&start);

    double *arr_BubbleSort = rng.readRandNums(fileName);
    bubbleSort(arr_BubbleSort,rng.arrSize);

    //get/print current time
    time(&end);
    cout << "Time ended: " << ctime(&end) << endl;

    ////////////////////////////////////////////////////////

    //Shell sort
    cout << "Shell sort" << endl;

    //get/print current time
    time(&start);
    cout << "Time started: " << ctime(&start);

    double *arr_ShellSort = rng.readRandNums(fileName);
    shellSort(arr_ShellSort,rng.arrSize);

    //get/print current time
    time(&end);
    cout << "Time ended: " << ctime(&end) << endl;

    ////////////////////////////////////////////////////////

  }
  else{
    cout << "Invalid input. Enter 'create' or 'sort'." << endl;
  }
  return 0;
}
