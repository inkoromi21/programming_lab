/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  double R, E, P, r, R_step, R_final;
  
  cout << "E = ";
  cin  >> E;
  
  cout << "r = ";
  cin  >> r;

  cout << "R = ";
  cin  >> R;

  cout << fixed << setprecision(2) << "\t \t" << endl;

  R_step = 10.0;
  R_final = 50.0;
    
  while (R < R_final) {
    P = R * (E / (R + r)) * (E / (R + r));

    cout << "R = " << R << "\t \t" << P << endl;
      
    // увеличение сопротивления до 50 Ом с шагом 10 Ом.
    R = R + R_step;
    
  }
  
  R_step = 50.0;
  R_final = 350.0;
  
  do {
    
    P = R * (E / (R + r)) * (E / (R + r));
  
    cout << "R = " << R << "\t \t" << P << endl;
      
    // увеличение сопротивления до 350 Ом с шагом 50 Ом.
    R = R + R_step;
  } while (R < R_final);
  
  return 0;
}
