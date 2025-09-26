/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
  double R, P, E, r;
  
  cout << "E = ";
  cin  >> E;
  
  cout << "r = ";
  cin  >> r;

  cout << "R = ";
  cin  >> R;

  while (R <= 40) {
    P = R * (E / (R + r)) * (E / (R + r));
    R = R + 10;

    cout << "R = " << R << "\t \t" << P << endl;
  }

  do {
    R = R + 50;
    P = R * (E / (R + r)) * (E / (R + r));
  
    cout << "R = " << R << "\t \t" << P << endl;
  
  } while (R < 300);
  
  return 0;
}
