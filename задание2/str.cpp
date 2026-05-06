#include "str.h"
#include <iostream>
using namespace std;

void String::print() const {
    cout << text << endl;
}

void String::input() {
    cin.getline(text, size + 1);

    // Если ввели больше, чем можно, очищаем лишние символы
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}