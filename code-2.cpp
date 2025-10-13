/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>

using namespace std;

int funcMinValB (double arrayElementMatrix, double arbitraryVariableB) {
  if (arrayElementMatrix < arbitraryVariableB) {
    return arrayElementMatrix;
  } else {
      return 0;
  }
}

int main() {
  int rowsMassiveG, colsMassiveG,rowsMassiveV, colsMassiveV;
  double sumOfSmallestElementG, sumOfSmallestElementV, arbitraryVariableB;
  
  sumOfSmallestElementV = 0.0;
  sumOfSmallestElementG = 0.0;
  
  cout << "введите значение b = ";
  cin  >> arbitraryVariableB;
  
  cout << "введите количество строк массива G = ";
  cin  >> rowsMassiveG;
  
  cout << "введите количество рядов массива G = ";
  cin  >> colsMassiveG;
  
  cout << "введите количество строк массива V = ";
  cin  >> rowsMassiveV;
  
  cout << "введите количество рядов массива V = ";
  cin  >> colsMassiveV;
  
  double matrixG[rowsMassiveG][colsMassiveG], matrixV[rowsMassiveV][colsMassiveV];
    
  cout << "Введите элементы матрицы G " << rowsMassiveG << "x" << colsMassiveG << ":\n";
  
  for (int rowsIndexG = 0; rowsIndexG < rowsMassiveG; ++rowsIndexG) {
    for (int colsIndexG = 0; colsIndexG < colsMassiveG; ++colsIndexG) {
      cout << "Элемент [" << rowsIndexG << "][" << colsIndexG << "]: ";
      cin  >> matrixG[rowsIndexG][colsIndexG];

      sumOfSmallestElementG += funcMinValB(matrixG[rowsIndexG][colsIndexG], arbitraryVariableB);
    }
  }
  
  cout << "Введите элементы матрицы V " << rowsMassiveV << "x" << colsMassiveV << ":\n";
  for (int rowsIndexV = 0; rowsIndexV < rowsMassiveV; ++rowsIndexV) {
    for (int colsIndexV = 0; colsIndexV < colsMassiveV; ++colsIndexV) {
      cout << "Элемент [" << rowsIndexV << "][" << colsIndexV << "]: ";
      cin  >> matrixV[rowsIndexV][colsIndexV];
      
      sumOfSmallestElementV += funcMinValB(matrixV[rowsIndexV][colsIndexV], arbitraryVariableB);
    }
  }
  
  cout << "\nРезультат\n" << " " << endl;
  
  cout << "сумма элементов массива V, меньших b = " << sumOfSmallestElementV << endl;
  cout << "сумма элементов массива G, меньших b = " << sumOfSmallestElementG << endl;
    
  return 0;
}