#include <vector>
#include <iterator>
#include <iostream>
#include "Sublist.h"

int main() {

  const int TARGET = 180;
  std::vector<int> dataSet;
  std::vector<Sublist> choices;
  int k, j, numSets, max, masterSum;
  bool foundPerfect;
  int indexOfBestChoice = 0;
  bool actionTaken = false;

  dataSet.push_back(20); 
  dataSet.push_back(12); 
  dataSet.push_back(22);
  /*
  dataSet.push_back(15); 
  dataSet.push_back(25);
  dataSet.push_back(19); 
  dataSet.push_back(29);
  dataSet.push_back(18);
  dataSet.push_back(11); 
  dataSet.push_back(13); 
  dataSet.push_back(17);
  */

  choices.clear();
  choices.push_back(Sublist(&dataSet));

  std::cout << "Target time: " << TARGET << std::endl;

  /*
  for j in dataSet
    size = choices.size
    for k in choices while k < size
        if choices[k].getSum() + dataSet[j] > target
            choices.push_back(the new subset)
  */

  for(auto intValue : dataSet) {

    int size = choices.size();
    for(int i = 0; i < size; i++) {
      if(choices[i].getSum() + intValue <= TARGET) {
        //choices.push_back( Sublist(dataSet) );
      }

    }
  }

  return 0;
}

/*
{}

{20}
{12}
{22}

{20,12}
{20,22}

{20,12,22}
*/
