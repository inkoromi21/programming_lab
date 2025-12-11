/*************************
* Автор: Воробьев Семен  *
* Вариант: 3             *
*************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int firstDayInMouth(int enteredYear, int enteredMonth) {
    int dayOfTheWeekIndexMixingCoefficient, coefficientForMonths, dayInWeek, secularShiftCoefficient, leapYearStep, centuryDivider, secondMonthCoefficient, firstMonthCoefficient, firstDayOfTheMonth, dayOfWeekFirstDay, conversionTheMonthOfJanuaryAndFebruaryForTheFormula, januaryAndFebruaryNumbers;
    
    conversionTheMonthOfJanuaryAndFebruaryForTheFormula = 12;
    januaryAndFebruaryNumbers = 3;
    firstDayOfTheMonth = 1;
    firstMonthCoefficient = 13;
    secondMonthCoefficient = 5;
    centuryDivider = 100;
    leapYearStep = 4;
    secularShiftCoefficient = 5;
    dayInWeek = 7;
    coefficientForMonths = 1;
    dayOfTheWeekIndexMixingCoefficient = 5;
    
    ++enteredMonth;
    
    if (enteredMonth < januaryAndFebruaryNumbers) {
        enteredMonth += conversionTheMonthOfJanuaryAndFebruaryForTheFormula;
        --enteredYear;
    }
    
    dayOfWeekFirstDay = (((firstDayOfTheMonth + (firstMonthCoefficient * (enteredMonth + coefficientForMonths)) / secondMonthCoefficient + (enteredYear % centuryDivider) + (enteredYear % centuryDivider) / leapYearStep + (enteredYear / centuryDivider) / leapYearStep + secularShiftCoefficient * (enteredYear / centuryDivider)) % dayInWeek) + dayOfTheWeekIndexMixingCoefficient) % dayInWeek;
    
    return dayOfWeekFirstDay;
}

string functionToAddSpacesBetweenMonthNames(string monthName) {
    string theResultOfTheSpaceAdditionFunction;
    int codingCoefficient, monthRowLength;
    
    codingCoefficient = 2;
    monthRowLength = 23;
    
    for (int spaceAdditionCounter = 0; spaceAdditionCounter < (monthRowLength - (monthName.length() / codingCoefficient )) ; ++spaceAdditionCounter) {
        theResultOfTheSpaceAdditionFunction += " ";
    }
    return theResultOfTheSpaceAdditionFunction;
}

string functionToAddSpacesToDaysOfTheMonth(int numberOfTheDayInTheMonth) {
  string theResultOfTheFunctionAddingSpacesToNumbers;
  int numberOfDigits;
    
  numberOfDigits = 9;
    
  if (numberOfTheDayInTheMonth <= numberOfDigits) {
    theResultOfTheFunctionAddingSpacesToNumbers = " " + to_string(numberOfTheDayInTheMonth) + " ";
  } else {
    theResultOfTheFunctionAddingSpacesToNumbers = to_string(numberOfTheDayInTheMonth) + " ";
  }
  return theResultOfTheFunctionAddingSpacesToNumbers;
}

pair <string,int> functionFirstRowOfTheMonth(int rowCounterInTheMonth, int counterOfDaysInTheMonth) {
    pair<string,int> firstRowOfTheMonthAndACounterOfDaysInAMonth;
    string temporaryRowVariable;
    int dayInWeek;
    
    dayInWeek = 7;
    
    if (rowCounterInTheMonth == 0) {
        for (int firstRowFunctionCounter = 0; firstRowFunctionCounter < dayInWeek; ++firstRowFunctionCounter) {
            temporaryRowVariable += functionToAddSpacesToDaysOfTheMonth(counterOfDaysInTheMonth);
            ++counterOfDaysInTheMonth;
        }
    } else {
        for (int firstRowFunctionCounter = 0; firstRowFunctionCounter < rowCounterInTheMonth; ++firstRowFunctionCounter) {
            temporaryRowVariable += "   ";
        }
        while (rowCounterInTheMonth < dayInWeek) {
            temporaryRowVariable += functionToAddSpacesToDaysOfTheMonth(counterOfDaysInTheMonth);
            ++counterOfDaysInTheMonth;
            ++rowCounterInTheMonth;
        }
        
    }
    firstRowOfTheMonthAndACounterOfDaysInAMonth = {temporaryRowVariable, counterOfDaysInTheMonth};
    
    return firstRowOfTheMonthAndACounterOfDaysInAMonth;
}

pair<string, int> functionMonthRowCreation(int NumberDayInMonth, int counterOfDaysInTheMonth) {
    pair<string, int> rowOfTheMonthAndACounterOfDaysInAMonth;
    int addedDaysCounter, dayInWeek, counterAlignmentUnit;
    string temporaryRowVariable;
    
    addedDaysCounter = 0;
    dayInWeek = 7;
    counterAlignmentUnit = 1;
    
    while ((addedDaysCounter < dayInWeek) && (counterOfDaysInTheMonth <= NumberDayInMonth)) {
        temporaryRowVariable += functionToAddSpacesToDaysOfTheMonth(counterOfDaysInTheMonth);
        ++addedDaysCounter;
        ++counterOfDaysInTheMonth;
    }
    
    for (int spaceCounter = 0; spaceCounter < dayInWeek; ++spaceCounter) {
        if ((counterOfDaysInTheMonth - counterAlignmentUnit ==  NumberDayInMonth) && (addedDaysCounter < dayInWeek)) {
            temporaryRowVariable += "   ";
            ++addedDaysCounter;
        }
    }
    
    rowOfTheMonthAndACounterOfDaysInAMonth = {temporaryRowVariable, counterOfDaysInTheMonth};
    
    return rowOfTheMonthAndACounterOfDaysInAMonth;
}

int main() {
    int centuralLeapYear, centureException, yearsInLeapCycle, addingASecondMonthToTheIndex, addingAThirdMonthToTheIndex, countOfLinesOfTheMonthWithoutTheFirst, numberOfMonthsToBeWithdrawn, countOfMonths, yoursYears, counterOfDaysInTheFirstMonth, counterOfDaysInTheSecondMonth, counterOfDaysInTheThirdMonth, daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string rowInTheFirstMounth, rowInTheSecondMounth, rowInTheThirdMounth, monthNames[] = {"январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"};
    
    countOfMonths = 12;
    yearsInLeapCycle = 4;
    centureException = 100;
    centuralLeapYear = 400;
    numberOfMonthsToBeWithdrawn = 3;
    countOfLinesOfTheMonthWithoutTheFirst = 5;
    addingASecondMonthToTheIndex = 1;
    addingAThirdMonthToTheIndex = 2;
    
    cout << "Введите год, календарь которого вам нужен: ";
    cin  >> yoursYears;
    
    cout << endl << "Календарь для " << yoursYears << " года." << endl << " " << endl;
    
    if ((yoursYears % yearsInLeapCycle == 0 && yoursYears % centureException != 0) || (yoursYears % centuralLeapYear == 0)) {
        daysInMonth[1] = {29};
    }
    
    for (int counterThreeMonthWithdrawal = 0; counterThreeMonthWithdrawal < countOfMonths; counterThreeMonthWithdrawal += numberOfMonthsToBeWithdrawn) {
        cout << monthNames[counterThreeMonthWithdrawal] << functionToAddSpacesBetweenMonthNames(monthNames[counterThreeMonthWithdrawal]) << monthNames[counterThreeMonthWithdrawal+addingASecondMonthToTheIndex] << functionToAddSpacesBetweenMonthNames(monthNames[counterThreeMonthWithdrawal+addingASecondMonthToTheIndex]) << monthNames[counterThreeMonthWithdrawal+addingAThirdMonthToTheIndex] << endl;
        
        counterOfDaysInTheFirstMonth = 1;
        counterOfDaysInTheSecondMonth = 1;
        counterOfDaysInTheThirdMonth = 1;
        
        rowInTheFirstMounth = "";
        rowInTheSecondMounth = "";
        rowInTheThirdMounth = "";
        
        for (int dayOfTheWeekCounter = 0; dayOfTheWeekCounter < numberOfMonthsToBeWithdrawn; ++dayOfTheWeekCounter) {
            cout << "пн вт ср чт пт сб вс   ";
        }
        
        
        cout << endl << functionFirstRowOfTheMonth(firstDayInMouth(yoursYears, counterThreeMonthWithdrawal), counterOfDaysInTheFirstMonth).first << "  " << functionFirstRowOfTheMonth(firstDayInMouth(yoursYears, counterThreeMonthWithdrawal+addingASecondMonthToTheIndex), counterOfDaysInTheSecondMonth).first << "  " << functionFirstRowOfTheMonth(firstDayInMouth(yoursYears, counterThreeMonthWithdrawal+addingAThirdMonthToTheIndex), counterOfDaysInTheThirdMonth).first << endl;
        
        counterOfDaysInTheFirstMonth = functionFirstRowOfTheMonth(firstDayInMouth(yoursYears, counterThreeMonthWithdrawal), counterOfDaysInTheFirstMonth).second;
        counterOfDaysInTheSecondMonth = functionFirstRowOfTheMonth(firstDayInMouth(yoursYears, counterThreeMonthWithdrawal+addingASecondMonthToTheIndex), counterOfDaysInTheSecondMonth).second;
        counterOfDaysInTheThirdMonth = functionFirstRowOfTheMonth(firstDayInMouth(yoursYears, counterThreeMonthWithdrawal+addingAThirdMonthToTheIndex), counterOfDaysInTheThirdMonth).second;
        
        for (int counterOfLinesOfTheMonthWithoutTheFirst = 0; counterOfLinesOfTheMonthWithoutTheFirst < countOfLinesOfTheMonthWithoutTheFirst; ++counterOfLinesOfTheMonthWithoutTheFirst) {
            
            cout << functionMonthRowCreation(daysInMonth[counterThreeMonthWithdrawal], counterOfDaysInTheFirstMonth).first << "  " << functionMonthRowCreation(daysInMonth[counterThreeMonthWithdrawal+addingASecondMonthToTheIndex], counterOfDaysInTheSecondMonth).first << "  " << functionMonthRowCreation(daysInMonth[counterThreeMonthWithdrawal+addingAThirdMonthToTheIndex], counterOfDaysInTheThirdMonth).first << endl;
            
            counterOfDaysInTheFirstMonth = functionMonthRowCreation(daysInMonth[counterThreeMonthWithdrawal], counterOfDaysInTheFirstMonth).second;
            counterOfDaysInTheSecondMonth = functionMonthRowCreation(daysInMonth[counterThreeMonthWithdrawal+addingASecondMonthToTheIndex], counterOfDaysInTheSecondMonth).second;
            counterOfDaysInTheThirdMonth = functionMonthRowCreation(daysInMonth[counterThreeMonthWithdrawal+addingAThirdMonthToTheIndex], counterOfDaysInTheThirdMonth).second;
        }
        cout << endl;
    }
    return 0;
}
        

