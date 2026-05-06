#include <clocale>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include "Date.h"
#include "Person.h"


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Создание объектов разными способами.
    Person first("Иванов", "Иван", "Иванович", Date(12, 5, 2004));
    Person second;
    Person third(first);

    // Заполнение объекта через сеттеры.
    second.setSurname("Петров");
    second.setName("Петр");
    second.setPatronymic("Петрович");
    second.setBirthDate(Date(7, 11, 2003));

    // Изменение скопированного объекта.
    third.setSurname("Сидоров");

    // Вывод информации на экран.
    first.print();
    second.print();
    third.print();

    std::cout << "Количество объектов Person: " << Person::getCount() << "\n";
}