#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct book {
  string authorSurname;
  string bookName;
  int yearOfPublication;
  int numberOfBooks;
  double bookPrice;
};

int main() {
  string necessaryAuthorSurname, oldestBook, temporaryVariableNumberRows;
  int temporaryVariableYearOfPublications,comparativeVariableIfThereAreNoBooks,bookListLength;
  double totalCostBooks;

  bookListLength = 0;
  totalCostBooks = 0;
  temporaryVariableYearOfPublications = 99999;
  comparativeVariableIfThereAreNoBooks = 0;
  
  cout << "Фамилия требуемого автора = ";
  cin >> necessaryAuthorSurname;

  ifstream fileLineCountVariable("file.txt");

  if (fileLineCountVariable.is_open()) {
    while (getline(fileLineCountVariable, temporaryVariableNumberRows)) {
      ++bookListLength;
      }
    fileLineCountVariable.close();
  }

  book bookList[bookListLength];
    
  cout << " " << endl << "Список книг " << necessaryAuthorSurname << ":" << endl;
  
  ifstream book("file.txt");

  if (book.is_open() == 0) {
    cout << " " << endl << "Ошибка открытия файла" << endl;
  } else {
    for (int bookIndex = 0; bookIndex < bookListLength; ++bookIndex) {
      book >> bookList[bookIndex].authorSurname >> bookList[bookIndex].bookName >> bookList[bookIndex].yearOfPublication >> bookList[bookIndex].numberOfBooks >> bookList[bookIndex].bookPrice;
        
      if (bookList[bookIndex].yearOfPublication < temporaryVariableYearOfPublications) {
        temporaryVariableYearOfPublications = bookList[bookIndex].yearOfPublication;
        oldestBook = bookList[bookIndex].bookName;
        }
        
      if (bookList[bookIndex].authorSurname == necessaryAuthorSurname) {
            comparativeVariableIfThereAreNoBooks = 1;
            
        cout << "'" << bookList[bookIndex].bookName << "'" << endl;
            
        totalCostBooks = totalCostBooks + bookList[bookIndex].bookPrice;
      }
    }
      
    if (comparativeVariableIfThereAreNoBooks == 0) {
      cout << "книг не обнаружено" << endl;
    }
      
    cout << " " << endl << "Старейшая книга - это " << "'" << oldestBook << "'" << ", она вышла в " << temporaryVariableYearOfPublications << " году" << endl << " " << endl;
      
    if (totalCostBooks == 0) {
      cout << " " << endl << "в списке не найдены книги данного автора, потому общую их стоимость посчитать невозможно" << endl << " " << endl;
    } else {
      cout << "общая стоимость книг " << necessaryAuthorSurname << " = " << totalCostBooks << " рублей" << endl << endl;
    }
    book.close();
  }
  return 0;
}

