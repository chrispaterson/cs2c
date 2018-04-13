#include <vector>
#include <iterator>
#include <iostream>
#include <math.h>
#include "Sublist.h"

int main() {

  const int TARGET = 180;
  std::vector<int> dataSet;
  std::vector<Sublist> choices;
  int k, j, numSets, max, masterSum;
  bool foundPerfect = false;
  Sublist ourWinner;

  dataSet.push_back(20); 
  dataSet.push_back(12); 
  dataSet.push_back(22);
  dataSet.push_back(15); 
  dataSet.push_back(25);
  dataSet.push_back(19); 
  dataSet.push_back(29);
  dataSet.push_back(18);
  dataSet.push_back(11); 
  dataSet.push_back(13); 
  dataSet.push_back(17);

  choices.clear();

  Sublist emptyList(&dataSet);
  choices.push_back(emptyList);

  std::cout << "Target time: " << TARGET << std::endl;

  int countOfGreater = 0;

  // outer loop through S (dataSet)
  for(int i = 0; i < dataSet.size() && !foundPerfect; i++) {

    int size = choices.size();
    // inner loop through choices or subsets L
    for(int j = 0; j < size; j++) {

      // current choice + current dataset item is less than or equal to the target
      if(choices[j].getSum() + dataSet[i] <= TARGET) {

        // create a new sublist
        Sublist sublist(&dataSet);

        // populate it with current sublist values
        sublist.addInitialIndicies(choices[j].getSublistVector());

        // add the index of the dataSet value
        sublist.addItem(i);

        // add the new sublist to our list of sublists
        choices.push_back(sublist);

        // set our current winner, or closest value to current choices[j]
        if(sublist.getSum() > ourWinner.getSum()) {
          ourWinner = sublist;
        }
      } else {
        countOfGreater ++; 
      }

      // if we have a perfect match
      if(choices[j].getSum() == TARGET) {

        // break everything
        foundPerfect = true;
        break;
      }
    }
  }


  ourWinner.showSublist();

  return 0;
}
