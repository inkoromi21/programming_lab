#include <iostream>
#include <fstream>
#include <map>
using namespace std;

char to_lower(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return ch - ('A' - 'a');
  }
  return ch;
}

bool is_letter(char ch) {
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int main() {
  char ch;
  char prev_char;
  map<char, int> repetitions;
  map<string, int> pairRepetitions;
  
  string pair = "";
  prev_char = '\0';
    
  ifstream file("file.txt");
    
  if (!file.is_open()) {
    cout << "Не удалось открыть файл" << endl;
    return 1;
    }
    
  while (file.get(ch)) {
    if (is_letter(ch)) {
      ch = to_lower(ch);
            
      repetitions[ch]++;
            
    if (prev_char != '\0') {
        
      pair += prev_char;
      pair += ch;
        
      pairRepetitions[pair]++;
    }
        
    prev_char = ch;
        
    } else {
      prev_char = '\0';
    }
  }
    
  for (const auto& pair : repetitions) {
    cout << "Символ '" << pair.first << "' встречается " << pair.second << " раз(а)." << endl;
  }
    
  cout << endl;
    
  for (const auto& pair : pairRepetitions) {
    cout << "Пара '" << pair.first << "' встречается " << pair.second << " раз(а)." << endl;
  }
    
  return 0;
}
