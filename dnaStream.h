/**
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment 1 - C++ Review
**/

#include <iostream>

using namespace std;

class dnaStream{

public:

  //instantiating all individual dna letters, and all possible pairs in each position

    double indA, indC, indT, indG;
    double pairAA, pairAC, pairAT, pairAG, pairCA, pairCC, pairCT, pairCG, pairTA, pairTC, pairTT, pairTG, pairGA, pairGC, pairGT, pairGG;

  //sum variables for both individuals and pairs

    double sumInd, sumPair;

  //instantiating mean, variance, and standard deviation for calculations

    double mean, var, stddev;

  //variable for amount of lines in the file to be read

    int lines;



  //Functions to count how many times each pair or individuals

    void countInd(string line);
    void countPair(string line);

  //Functions for calculations of the mean, variance, standard deviation, and the sums of both individual dna and dna pairs
    double calcMean();
    double calcVar();
    double calcStddev();
    double calcSumInd();
    double calcSumPair();

  //Setting up the functions that will input the file with the DNA strings and output the returns

    void fileIn(string fileName);
    void fileOut(string fileName);

  //Function for obtaining the length of each line of the file input.

    int getLength();

};
