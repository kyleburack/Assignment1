/**
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment 1 - C++ Review
**/

#include <iostream>
#include "dnaStream.h"
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

dnaStream::dnaStream(){

//setting all variables to default values

  indA = 0;
  indC = 0;
  indT = 0;
  indG = 0;
  pairAA = 0;
  pairAC = 0;
  pairAT = 0;
  pairAG = 0;
  pairCA = 0;
  pairCC = 0;
  pairCT = 0;
  pairCG = 0;
  pairTA = 0;
  pairTC = 0;
  pairTT = 0;
  pairTG = 0;
  pairGA = 0;
  pairGC = 0;
  pairGT = 0;
  pairGG = 0;

  sumInd = 0;
  sumPair = 0;

  mean = 0;
  var = 0;
  stddev = 0;

  lines = 0;

}

  void dnaStream::countInd(string line){
    for(int i = 0; i < line.length(); i++){
      if(toupper(line[i] == 'A')){
        ++indA;
      }
      else if(toupper(line[i]) == 'C'){
        ++indC;
      }
      else if(toupper(line[i]) == 'T'){
        ++indT;
      }
      else if(toupper(line[i]) == 'G'){
        ++indG;
      }
    }
    countPair(line);
  }

  void dnaStream::countPair(string line){
    int j;
    for(int i = 0; i < line.length(); i++){
      if(i == line.length()){
        break;
      }
      else{
        //variable j is the char after i which is the second char in the pair block.

        j = i + 1;

        //Checks the first char to see which letter it is, then the one directly after to make a pair.

        if(toupper(line[i] == 'A')){
            if(toupper(line[j]) == 'A'){
              ++pairAA;
            }
            else if(toupper(line[j]) == 'C'){
              ++pairAC;
            }
            else if(toupper(line[j]) == 'T'){
              ++pairAT;
            }
            else if(toupper(line[j]) == 'G'){
              ++pairAG;
            }
        }
        else if(toupper(line[i]) == 'C'){
            if(toupper(line[j]) == 'A'){
              ++pairCA;
            }
            else if(toupper(line[j]) == 'C'){
              ++pairCC;
            }
            else if(toupper(line[j]) == 'T'){
              ++pairCT;
            }
            else if(toupper(line[j]) == 'G'){
              ++pairCG;
            }
        }
        else if(toupper(line[i]) == 'T'){
            if(toupper(line[j]) == 'A'){
              ++pairTA;
            }
            else if(toupper(line[j]) == 'C'){
              ++pairTC;
            }
            else if(toupper(line[j]) == 'T'){
              ++pairTT;
            }
            else if(toupper(line[j]) == 'G'){
              ++pairTG;
            }
        }
        else if(toupper(line[i]) == 'G'){
            if(toupper(line[j]) == 'A'){
              ++pairGA;
            }
            else if(toupper(line[j]) == 'C'){
              ++pairGC;
            }
            else if(toupper(line[j]) == 'T'){
              ++pairGT;
            }
            else if(toupper(line[j]) == 'G'){
              ++pairGG;
            }
        }
      }
    }
  }

  double dnaStream::calcSumInd(){
    sumInd = indA + indC + indT + indG;
    cout << "Sum: " << sumInd << "\n";
    return sumInd;
  }

  double dnaStream::calcSumPair(){
    sumPair = pairAA + pairAC + pairAT + pairAG + pairCA + pairCC + pairCT + pairCG + pairTA + pairTC + pairTT + pairTG + pairGA + pairGC + pairGT + pairGG;
    cout << "Sum: " << sumPair << "\n";
    return sumPair;
  }

  double dnaStream::calcMean(){
    mean = sumInd / lines;
    cout << "Mean: " << mean << "\n";
    return mean;
  }

  double dnaStream::calcVar(){
    var = (((indA - mean) * (indA - mean)) + ((indC - mean) * (indC - mean)) + ((indT - mean) * (indT - mean)) + ((indG - mean) * (indG - mean))) / lines;
    cout << "Variance: " << var << "\n";
    return var;
  }

  double dnaStream::calcStddev(){
    stddev = sqrt(var);
    cout << "Standard Deviation: " << stddev << "\n";
    return stddev;
  }

  void dnaStream::fileIn(string fileName){
      string local;
      ifstream myfile (fileName.c_str());
      if(myfile.is_open()){
        while(getline(myfile, local)){
          ++lines;
          countInd(local);
        }
        cout << "Number of Lines: " << lines << "\n";
        calcSumInd();
        calcSumPair();
        calcMean();
        calcVar();
        calcStddev();
      }
      else{
        cout << "File not available to be opened.";
      }
  }

  void dnaStream::fileOut(string fileName){
    ifstream myfile (fileName.c_str());

    if(myfile.is_open()){

//probability of each of the individual dna letters to occur in the file.

      double probA, probC, probT, probG;
      probA = indA / sumInd;
      probC = indC / sumInd;
      probT = indT / sumInd;
      probG = indG / sumInd;

//Information about myselft, and the describtion of the dna text file

      cout << "Kyle Burack \n 2288845 \n burack@chapman.edu \n CPSC350-1 \n Assignment 1- C++ review" << "\n";
      cout << "Sum: " << sumInd << "\n";
      cout << "Mean: " << mean << "\n";
      cout << "Variance: " << var << "\n";
      cout << "Standard Deviation: " << stddev << "\n";

      cout << "Probability of A: " << probA << "\n";
      cout << "Probability of C: " << probC / sumInd << "\n";
      cout << "Probability of T: " << probT / sumInd << "\n";
      cout << "Probability of G: " << probG / sumInd << "\n";
      cout << "Probability of AA: " << pairAA / sumPair << "\n";
      cout << "Probability of AC: " << pairAC / sumPair << "\n";
      cout << "Probability of AT: " << pairAT / sumPair << "\n";
      cout << "Probability of AG: " << pairAG / sumPair << "\n";
      cout << "Probability of CA: " << pairCA / sumPair << "\n";
      cout << "Probability of CC: " << pairCC / sumPair << "\n";
      cout << "Probability of CT: " << pairCT / sumPair << "\n";
      cout << "Probability of CG: " << pairCG / sumPair << "\n";
      cout << "Probability of TA: " << pairTA / sumPair << "\n";
      cout << "Probability of TC: " << pairTC / sumPair << "\n";
      cout << "Probability of TT: " << pairTT / sumPair << "\n";
      cout << "Probability of TG: " << pairTG / sumPair << "\n";
      cout << "Probability of GA: " << pairGA / sumPair << "\n";
      cout << "Probability of GC: " << pairGC / sumPair << "\n";
      cout << "Probability of GT: " << pairGT / sumPair << "\n";
      cout << "Probability of GG: " << pairGG / sumPair << "\n";

      for(int i = 0; i < 1000; ++i){

        int gaussian = getLength();

        for(int j = 0; j < gaussian; ++j){

//For each gaussian distribution length of line, these variables give us the average number of each dna letter to print out to the file.

            int gauA, gauC, gauT, gauG;
            gauA = probA * gaussian;
            gauC = probC * gaussian;
            gauT = probT * gaussian;
            gauG = probG * gaussian;

              if(j < gauA){

                cout << "A";

              }

              else if(j < gauA + gauC){

                cout << "C";

              }

              else if(j < gauA + gauC + gauT){

                cout << "T";

              }

              else if(j < gauA + gauC + gauT + gauG){

                cout << "G";

              }

            }

          }

      }

      else{

        cout << "File not available to be used.";

      }
}

  int dnaStream::getLength(){
    double c = sqrt((-2)* log( rand() / RAND_MAX)) * cos(2 * 3.1415926535987 * (rand() / RAND_MAX));
    double d = stddev * c + mean;
    return d;
  }
