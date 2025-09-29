/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double R, E, P, r;
  
  cout << "E = ";
  cin  >> E;
  
  cout << "r = ";
  cin  >> r;

  cout << "R = ";
  cin  >> R;

  cout << fixed << setprecision(2) << "\t \t" << endl;
    
  while(R < 50.0) {
    P = R * (E / (R + r)) * (E / (R + r));

    cout << "R = " << R << "\t \t" << P << endl;
      
    // увеличение сопротивления до 50 Ом с шагом 10 Ом.
    R = R + 10.0 ;
    
  }

  do {
    P = R * (E / (R + r)) * (E / (R + r));
  
    cout << "R = " << R << "\t \t" << P << endl;
      
    // увеличение сопротивления до 350 Ом с шагом 50 Ом.
    R = R + 50.0;
  } while(R < 350.0);
  
  return 0;
}
