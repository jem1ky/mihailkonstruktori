#pragma once
class Date
{
    // Поля даты рождения.
    int day, month, year;

public:
    // Конструктор с параметрами по умолчанию.
    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    void print() const;
};

