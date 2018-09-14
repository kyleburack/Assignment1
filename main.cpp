/**
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment 1 - C++ Review
**/

#include <iostream>
#include "dnaStream.h"
#include "dnaStream.cpp"

using namespace std;

int main(int argc, char *argv[]){

  dnaStream dna;

  bool continues = true;

  while(continues == true){

    cout << "Enter name of file. \n";
    string file;
    string reading = "yes";
    getline(cin, file);
    dna.fileIn(file);
    dna.fileOut("kyleburack.out");

    cout << "Would you like to process another file? (Enter NO to exit, Enter anything else to continue.) \n";
    getline(cin, reading);
    if(reading == "no" || reading == "No" || reading == "NO"){
      continues = false;
      cout << "Thank you for analyzing your DNA file. \n";
    }
    else{
      continue;
    }

  }

  return 0;

}
