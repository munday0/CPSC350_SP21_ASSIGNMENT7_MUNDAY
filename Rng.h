/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 7
*/

//Header file for Rng

#ifndef RNG_H
#define RNG_H
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
using namespace std;

class Rng{
private:
public:
  Rng(); //constructor
  ~Rng(); //destructor
  double* arrToSort;
  int arrSize;

  //random number generator - takes in int for num to gen & file name, writes to file
  void writeRandNums(int num, string fileName);

  //reads in random nums from file and stores in array - first line is size of array
  double* readRandNums(string fileName); //returns pointer to array
};

#endif
