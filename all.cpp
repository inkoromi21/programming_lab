/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>

using namespace std;

int main() {
  int rows, cols, quantityMainDiagonal, sumMainDiagonal;
  
  sumMainDiagonal = 0;
  quantityMainDiagonal = 0;
  
  cout << "введите количество строк = ";
  cin  >> rows;
  
  cout << "введите количество рядов = ";
  cin  >> cols;
  
  int matrix[rows][cols];
    
  cout << "Введите элементы матрицы " << rows << "x" << cols << ":\n";
  
  for (int rowsCounter = 0; rowsCounter < rows; ++rowsCounter) {
    for (int colsCounter = 0; colsCounter < cols; ++colsCounter) {
      cout << "Элемент [" << rowsCounter << "][" << colsCounter << "]: ";
      cin >> matrix[rowsCounter][colsCounter];
    }
  }

  cout << "\nВведенная матрица\n";
    
  for (int rowsCounter = 0; rowsCounter < rows; ++rowsCounter) {
    for (int colsCounter = 0; colsCounter < cols; ++colsCounter) {
      if (colsCounter < rowsCounter) {
        quantityMainDiagonal = quantityMainDiagonal + 1;
        sumMainDiagonal = sumMainDiagonal + matrix[rowsCounter][colsCounter];
      }  
      cout << matrix[rowsCounter][colsCounter] << "\t";
    }
    cout << endl;
  }
  
  cout << "количество элементов главной диагонали = " << quantityMainDiagonal << endl;
  cout << "сумма элементов главной диагонали = " << sumMainDiagonal << endl;
    
  return 0;
}