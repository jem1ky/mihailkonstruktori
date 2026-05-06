#include "Person.h"
#include <iostream>


//вывод
void Person::print() const {
    std::cout << "ID: " << id << "\n"
        << "Фамилия: " << surname << "\n"
        << "Имя: " << name << "\n"
        << "Отчество: " << patronymic << "\n"
        << "Дата рождения: ";
    birthDate.print();
    std::cout << "\n\n";
}

int Person::count = 0;