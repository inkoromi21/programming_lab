/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

bool checkingRomanOrArabicNumber(string theEnteredStringWithTheNumber) {
  if (theEnteredStringWithTheNumber.empty()) {
    return false;
  }
    
  for (int numberVerificationCounter = 0; numberVerificationCounter < theEnteredStringWithTheNumber.length(); numberVerificationCounter++) {
    char currentChar = theEnteredStringWithTheNumber[numberVerificationCounter];
      
    if (!isdigit(static_cast<unsigned char>(currentChar))) {
      return false;
    }
  }
  return true;
}

string romanNumerals(int theEnteredArabicNumber) {
  const vector<string> romanNumbers {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  const vector<int> arabNumbers {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string resultRomanNumerals;
    
  resultRomanNumerals = "";

  for (int romanNumberCounter = 0; romanNumberCounter < arabNumbers.size(); romanNumberCounter++) {
    while (theEnteredArabicNumber >= arabNumbers[romanNumberCounter]) {
      resultRomanNumerals += romanNumbers[romanNumberCounter];
      theEnteredArabicNumber -= arabNumbers[romanNumberCounter];
    }
  }

    return resultRomanNumerals;
}

int getValue(char romanChar) {
  switch (romanChar) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return 0;
  }
}

int arabNumerals(string theIntroducedRomanNumber) {
  int resultArabNumerals, lengthString, currentVal, nextVal, unitToCheckForTheNextCharacter;
    
  resultArabNumerals = 0;
  unitToCheckForTheNextCharacter = 1;
  lengthString = theIntroducedRomanNumber.length();

  for (int ArabicNumberCounter = 0; ArabicNumberCounter < lengthString; ArabicNumberCounter++) {
    currentVal = getValue(theIntroducedRomanNumber[ArabicNumberCounter]);
        
    if (ArabicNumberCounter + unitToCheckForTheNextCharacter < lengthString) {
      nextVal = getValue(theIntroducedRomanNumber[ArabicNumberCounter + unitToCheckForTheNextCharacter]);
        
      if (currentVal < nextVal) {
        resultArabNumerals += (nextVal - currentVal);
        ArabicNumberCounter++;
      } else {
        resultArabNumerals += currentVal;
      }
    } else {
      resultArabNumerals += currentVal;
    }
  }

  return resultArabNumerals;
}



int main() {
  string userEnteredNumber, finalResult;
    
  cout << "Введите свое число = ";
  cin >> userEnteredNumber;
    
  if (checkingRomanOrArabicNumber(userEnteredNumber)) {
    finalResult = romanNumerals(stoi(userEnteredNumber));
      
    cout << " " << endl << "Ваше число, написанное римскими цифрами = " << finalResult << endl << " " << endl;
  } else {
    finalResult = to_string(arabNumerals(userEnteredNumber));
      
    cout << " " << endl << "Ваше число, написанное арабскими цифрами = " << finalResult << endl << " " << endl;
  }

    return 0;
}
