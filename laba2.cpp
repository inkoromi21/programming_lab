/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  const int n = 10;
  int i;
  double R[n], P, E, r;
 
  cout << "E = ";
  cin >> E;

  cout << "r = ";
  cin >> r;
 
  cout << "Введите 10 элементов:" << endl;
  for (i = 0; i < 10; i++) {
    cin >> R[i];
} 
  cout  << "\t"  << "R" << "\t \t" << "P"  << endl;
  cout  << fixed << setprecision(3);

  for (i = 0; i < 10; i++) {
  P = R[i] * pow(E / (R[i] + r), 2);
  cout  << "\t " << R[i] << "\t  \t " << P << endl;
}
 return 0;
}