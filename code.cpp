/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double A, d, R, n, j;
  int endOfRepeatValue, numberOfDecimalPlaces;
    
  cout << "d = ";
  cin  >> d;
    
  cout << "n = ";
  cin  >> n;

  d = d / 10.0;
  
  endOfRepeatValue = 7;
  numberOfDecimalPlaces = 4;
  
  cout << fixed << setprecision(numberOfDecimalPlaces) << "\t \t" << endl;
    
  for (int numberOfRepetitions = 0; numberOfRepetitions < endOfRepeatValue; ++numberOfRepetitions) {
    cout << "j = ";
    cin  >> j;
    

    R = (j * 100.0 * d) / n;
    
    if (R > (9.2 * pow(10.0, 5.0))) {
      A = 0.021 / pow(d, 0.3);
    } else {
      A = pow(((1.5 * pow(10.0, -6.0)) / d + (1.0 / R)), 0.3);
    }
    
    cout << "R = " << R << "    " << "A = " << A << endl << " " << endl;
    }
  return 0;
}
    
