/**
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment 1 - C++ Review
**/

#include <iostream>;
#include "dnaStream.h"

using namespace std;

int main(int argc, char argv[]){

  dnaStream dna;

  bool continues = true;

  while(continues == true){

    cout << "Enter name of file. \n"
    string file;
    string reading = "yes";
    cin >> file;
    dna.fileIn(file);
    dna.fileOut("kyleburack.txt");

    cout << "Would you like to process another file? (Enter NO to exit, Enter anything else to continue.) \n";
    cin >> reading;
    if(tolower(reading) == "no"){
      continues = false;
      cout << "Thank you for analyzing your DNA file. \n"
    }
    else{
      continue;
    }

  }

  return 0;
}
