/*
Stephanie Munday
2343625
smunday@chapman.edu
CPSC-350-08
Assignment 7
*/

//Cpp file for Rng

#include "Rng.h"

//constructor
Rng::Rng(){}

//destructor
Rng::~Rng(){
  delete[] arrToSort;
}

//random number generator - takes in int for num to gen & file name
//generates num random doubles and writes them to the file line by line
//first line should be the num of generated doubles
void Rng::writeRandNums(int num, string fileName){
  //create/open files to write to
  std::ofstream writeFile;
  writeFile.open(fileName);

  //if file is open
  if (writeFile.is_open()) {
    writeFile << num << endl; //write num to file
    std::srand(time(0)); //seed rng
    for (int i = 0; i < num; i++) { //generate random numbers num times
      writeFile << (double)std::rand() << endl; //write each to file
    }
  }
  writeFile.close();
}

//reads in random nums from file and stores in array - first line is size of array
//returns pointer to array
double* Rng::readRandNums(string fileName){
  //create/open files to read from
  std::ifstream readFile;
  readFile.open(fileName);

  string readNum = "";
  int count = 0;

  if (readFile.is_open()) {
    getline(readFile, readNum); //gets the total number of random numbers in file
    arrSize = stod(readNum);
    arrToSort = new double[arrSize];
    while (getline(readFile, readNum)) { //gets line and stores in variable readNum
      arrToSort[count++] = stod(readNum); //assigns readNum to position in array
    }
    return arrToSort;
  }
  readFile.close();
}
