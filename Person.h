#include <iostream>
#include "Date.h"
#pragma once
class Person
{
        // Основные поля класса "Человек".
    int id;
        char* surname;
        char* name;
        char* patronymic;
        Date birthDate;
        static int count;

        // Выделяет динамическую память и копирует в неё строку.
        static char* copy(const char* text)
        {
            if (!text) text = "";
            size_t size = std::strlen(text) + 1;
            char* result = new char[size];
            strcpy_s(result, size, text);
            return result;
        }

        // Меняет строковое поле: удаляет старую память и записывает новое значение.
        void change(char*& field, const char* value)
        {
            delete[] field;
            field = copy(value);
        }

    public:
        // Конструктор с параметрами.
        Person(const char* s, const char* n, const char* p, Date date)
            : id(count+1), surname(copy(s)), name(copy(n)), patronymic(copy(p)), birthDate(date)
        {
            count++;
        }

        // Конструктор по умолчанию вызывает конструктор с параметрами.
        Person() : Person("Не указана", "Не указано", "Не указано", Date()) {}

        // Конструктор копирования создаёт отдельные копии строк.
        Person(const Person& other)
            : Person(other.surname, other.name, other.patronymic, other.birthDate) {
        }

        // Деструктор освобождает динамическую память.
        ~Person()
        {
            delete[] surname;
            delete[] name;
            delete[] patronymic;
            count--;
        }

        // Геттеры.
        const char* getSurname() const { return surname; }
        const char* getName() const { return name; }
        const char* getPatronymic() const { return patronymic; }
        Date getBirthDate() const { return birthDate; }

        // Сеттеры.
        void setSurname(const char* value) { change(surname, value); }
        void setName(const char* value) { change(name, value); }
        void setPatronymic(const char* value) { change(patronymic, value); }
        void setBirthDate(Date value) { birthDate = value; }

        static int getCount() { return count; }

        // Вывод информации о человеке.
        void print() const;
};

