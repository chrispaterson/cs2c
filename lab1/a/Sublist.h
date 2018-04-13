
#include <vector>

class Sublist
{
  public:
    Sublist(std::vector<int> * orig = NULL);
    
    bool addItem( int indexOfItemToAdd );
    void showSublist() const;
    int getSum() const;

  private:

    int sum;
    std::vector<int> *originalObjects;
    std::vector<int> indices;
};
