/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
  int R, E;
  double P, r;
  
  cout << "E = ";
  cin  >> E;
  
  cout << "r = ";
  cin  >> r;

  cout << "R = ";
  cin  >> R;

  cout << fixed << setprecision(2) << "\t \t" << endl;
    
  while (R < 50) {
    P = R * (E / (R + r)) * (E / (R + r));

    cout << "R = " << R << "\t \t" << P << endl;

    R = R + 10;
  }

  do {
    P = R * (E / (R + r)) * (E / (R + r));
  
    cout << "R = " << R << "\t \t" << P << endl;

    R = R + 50;
  } while (R <= 300);
  
  return 0;
}