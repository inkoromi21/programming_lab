/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int years, ValueOfTheFirstDayOfTheYear, yearOfTheDesiredCentury, centuryOfTheDesiredYear, numberJanuary, coefficientForZellersAlgorithm, variableForLineOffset, numberOfMonths, variableForCalculatingTheDayOfTheWeek, currentMonthDays, daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  string month[] = {"январь","февраль","март","апрель","май","июнь","июль","август","сентябрь","октябрь","ноябрь","декабрь"};
    
  cout << "Введите год, календарь которого вам требуется = ";
  cin  >> years;
    
  cout << " " << endl;
    
  ValueOfTheFirstDayOfTheYear = 1;
  centuryOfTheDesiredYear = years / 100;
  yearOfTheDesiredCentury = (years - ValueOfTheFirstDayOfTheYear) % 100;
  numberJanuary = 13;
  numberOfMonths = 12;
  coefficientForZellersAlgorithm = 2;
    
  //Здесь используется формула Зеллера, которая считает день недели 1 января определенного года.
  variableForCalculatingTheDayOfTheWeek = (ValueOfTheFirstDayOfTheYear + ((numberJanuary + ValueOfTheFirstDayOfTheYear) * 13 / 5) + yearOfTheDesiredCentury + yearOfTheDesiredCentury / 4 + centuryOfTheDesiredYear / 4 - 2 * centuryOfTheDesiredYear) % 7;
    
  if (((years % 4 == 0) && (years % 100 != 0)) || (years % 400 == 0)) {
    daysInMonth[1] = {29};
  }
    
  variableForLineOffset = variableForCalculatingTheDayOfTheWeek - coefficientForZellersAlgorithm;
    
  for (int monthCounter = 0; monthCounter < numberOfMonths; ++monthCounter) {
    cout << month[monthCounter] << endl;
    currentMonthDays = daysInMonth[monthCounter];
        
    cout << "пн " << "вт " << "ср " << "чт " << "пт " << "сб " << "вс " << endl;
        
    for (int indentCounter = 0; indentCounter < variableForLineOffset; ++indentCounter) {
      cout << "   ";
    }
        
    for (int dayCounter = 1; dayCounter <= currentMonthDays; ++dayCounter) {
            
      if (variableForLineOffset < 6) {
        if (dayCounter < 10) {
          cout << " "<< dayCounter << " ";
          ++variableForLineOffset;
        } else {
          cout << dayCounter << " ";
          ++variableForLineOffset;
        }
      } else {
        if (dayCounter < 10) {
          cout << " " << dayCounter << " " << endl;
          variableForLineOffset = 0;
        } else {
          cout <<  dayCounter << " " << endl;
          variableForLineOffset = 0;
        }
      }
    }
            cout << endl << endl;
  }
    return 0;
}
