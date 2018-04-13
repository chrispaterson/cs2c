#include <iostream>
#include <string>
#include "Sublist.h"

const std::string TAB = "  ";

Sublist::Sublist( std::vector<int> *orig) : sum(0), originalObjects(orig) 
{};

bool Sublist::addItem( int indexOfItemToAdd ) 
{

  indices.push_back( indexOfItemToAdd );
  sum += originalObjects->at( indexOfItemToAdd );

  return true;
}

void Sublist::showSublist() const 
{
  

  std::cout << "Sublist -------------------------" << std::endl;
  std::cout << TAB << "sum: " << getSum() << std::endl;

  for(int i = 0; i < indices.size(); i++) {

    std::cout << TAB << "array[" << i << "] = " << originalObjects->at(indices.at(i)) << ',';
  }

}

int Sublist::getSum() const 
{ 

  return sum; 
}
std::vector<int> * Sublist::getSublistVector() {

  return &indices;
}
void Sublist::addInitialIndicies(std::vector<int> * initIndicies) {

  for(auto index : *initIndicies) {
    indices.push_back(index);
  }

}
