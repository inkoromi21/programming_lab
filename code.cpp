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
  int count, count_max;
    
  cout << "d = ";
  cin  >> d;
    
  cout << "n = ";
  cin  >> n;

  d = d / 10.0;
  
  count_max = 7;
  count = 0;
  
  cout << fixed << setprecision(4) << "\t \t" << endl;
    
  for (count; count < count_max; ++count) {
    cout << "j = ";
    cin  >> j;
    

    R = (j * 100 * d) / n;
    
    if (R > (9.2 * pow(10.0, 5.0))) {
      A = 0.021 / pow(d, 0.3);
    } else {
      A = pow(((1.5 * pow(10.0, -6.0)) / d + (1.0 / R)), 0.3);
    }
    
    cout << "R = " << R << "    " << "A = " << A << endl << " " << endl;
    }
  return 0;
}
    